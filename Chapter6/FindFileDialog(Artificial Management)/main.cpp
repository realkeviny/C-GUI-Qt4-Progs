#include "FindFileDialogArtificialManagement.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindFileDialogArtificialManagement w;
    w.show();
    return a.exec();
}
