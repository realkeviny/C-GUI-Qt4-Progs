#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    void paintEvent(QPaintEvent* event) override;

private:
    Ui::MyWidgetClass ui;
};
