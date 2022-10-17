#include <QDialog>
#include <QtWidgets/QApplication>

#include "ui_gotocell.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ui::GoToCellDialog ui;
    QDialog* dialog = new QDialog;
    ui.setupUi(dialog);
    dialog->show();

    return a.exec();
}
