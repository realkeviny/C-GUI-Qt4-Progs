#include "finddialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    finddialog* dialog = new finddialog;
    dialog->show();
    return a.exec();
}
