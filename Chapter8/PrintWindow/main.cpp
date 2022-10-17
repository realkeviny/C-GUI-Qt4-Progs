#include "PrintWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    class PrintWindow w;
    w.show();
    return a.exec();
}
