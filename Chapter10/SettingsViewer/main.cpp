#include "SettingsViewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SettingsViewer w;
    w.show();
    return a.exec();
}
