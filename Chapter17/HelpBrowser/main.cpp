#include "HelpBrowser.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelpBrowser w;
    w.show();
    return a.exec();
}
