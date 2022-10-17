#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Example1.h"

class Example1 : public QMainWindow,private Ui::Example1Class
{
    Q_OBJECT

public:
    Example1(QWidget *parent = nullptr);
    ~Example1();

};
