#pragma once

#include <QtWidgets/QDialog>
#include "ui_CustomerInfoDialog.h"

class CustomerInfoDialog : public QDialog
{
    Q_OBJECT

public:
    CustomerInfoDialog(QWidget *parent = nullptr);
    ~CustomerInfoDialog();

    bool eventFilter(QObject* watched, QEvent* event) override;
private:
    Ui::CustomerInfoDialogClass ui;
};
