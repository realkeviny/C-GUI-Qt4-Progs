#include "TeamLeadersDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList leaders;
    leaders << "Capter Stone" << "Frank Fucks" << "B-O2" << "Trollface"
        << "Campbell" << "DodgeFire";
    TeamLeadersDialog dialog(leaders);
    dialog.show();
    return a.exec();
}
