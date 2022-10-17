#include <QtWidgets>

#include "Candy.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStyleFactory::create("Fusion");

    QFile file(":/Style/Candy.qss");
    file.open(QFile::ReadOnly);
    app.setStyleSheet(file.readAll());

    CandyDialog dialog;
    dialog.show();

    return app.exec();
}
