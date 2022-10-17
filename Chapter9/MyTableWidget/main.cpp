#include "MyTableWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTableWidget w;
    w.show();
    return a.exec();
}
