#include "ThreadDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadDialog dialog;
    dialog.show();
    return a.exec();
}
