#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Hello.h"

class Hello : public QMainWindow
{
    Q_OBJECT

public:
    Hello(QWidget *parent = nullptr);
    ~Hello();

private:
    Ui::HelloClass ui;
};
