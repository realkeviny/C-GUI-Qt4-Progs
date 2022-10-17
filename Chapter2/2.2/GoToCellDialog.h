#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

#include "ui_gotocell.h"

class GoToCellDialog :
    public QDialog,public Ui::GoToCellDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget* parent = nullptr);

private slots:
    void on_lineedit_textChanged();
};


#endif
