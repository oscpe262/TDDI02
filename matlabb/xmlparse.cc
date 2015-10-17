#include<iostream>
#include<QCoreApplication>
#include<QDebug>

using namespace std;

bool XmlStreamReader::readFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    std::cerr << "Error: Cannot read file " << qPrintable(fileName)
	      << ": " << qPrintable(file.errorString())
	      << std::endl;
    return false;
  }
  reader.setDevice(&file);

  reader.readNext();
  while (!reader.atEnd()) {
    if (reader.isStartElement()) {
      if (reader.name() == "recipe") {
	readnameElement();
      } else {
	reader.raiseError(QObject::tr("meh"));
      }
    } else {
      reader.readNext();
    }
  }    file.close();
  if (reader.hasError()) {
    std::cerr << "Error: Failed to parse file "
	      << qPrintable(fileName) << ": "
	      << qPrintable(reader.errorString()) << std::endl;
    return false;
  } else if (file.error() != QFile::NoError) {
    std::cerr << "Error: Cannot read file " << qPrintable(fileName)
	      << ": " << qPrintable(file.errorString())
	      << std::endl;
    return false;
  }
  return true;
}
    

class XmlStreamReader
{
public:
  XmlStreamReader(QTreeWidget *tree);
  bool readFile(const QString &filename);

private:
  void readnameElement();
  void readingredientElement(QTreeWidgetItem *parent);
  void readinstructionElement(QTreeWidgetItem *parent);
  void skipUnknownElement();
  
  QTreeWidget *treeWidget;
  QXmlStreamReader reader;
};

int main (int argc, char *argv[])
{
   QApplication app(argc, argv);
   QStringList args = QApplication::arguments();

   QTreeWidget treeWidget;
    
   XmlStreamReader reader(&treeWidget);
   for (int i = 1; i < args.count(); ++i)
     reader.readFile(args[i]);
   return app.exec();
}
