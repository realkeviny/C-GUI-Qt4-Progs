#include "TextArtDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextArtDialog dialog(QObject::tr("Text Art"));
    dialog.resize(600, 300);
    dialog.show();
    return a.exec();
}