#include "FindFileDialogLayoutManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindFileDialogLayoutManager w;
    w.show();
    return a.exec();
}
