#include "Diagram.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Diagram w;
    w.show();
    return a.exec();
}
