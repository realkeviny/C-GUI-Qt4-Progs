#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Age.h"

class Age : public QMainWindow
{
    Q_OBJECT

public:
    Age(QWidget *parent = nullptr);
    ~Age();

private:
    Ui::AgeClass ui;
};
