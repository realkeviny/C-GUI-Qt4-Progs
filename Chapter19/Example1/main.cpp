#include "Example1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Example1 w;
    w.show();
    return a.exec();
}
