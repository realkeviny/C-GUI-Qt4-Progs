#include "BooleanWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BooleanWindow window;
    window.show();
    return a.exec();
}
