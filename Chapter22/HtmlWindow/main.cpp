#include "HtmlWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HtmlWindow w;
    w.show();
    return a.exec();
}
