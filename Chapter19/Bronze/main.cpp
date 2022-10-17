#include "Bronze.h"
#include "BronzeDialog.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setStyle(new Bronze);
    BronzeDialog dialog;
    dialog.layout()->setSpacing(7);
    dialog.layout()->setContentsMargins(7, 7, 7, 7);
    dialog.show();

    return app.exec();
}
