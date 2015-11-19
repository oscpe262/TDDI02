#include "classes/headers/matlabb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatLabb w;
    w.show();

    return a.exec();
}
