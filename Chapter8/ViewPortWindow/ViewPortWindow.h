#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ViewPortWindow.h"

class ViewPortWindow : public QMainWindow
{
    Q_OBJECT

public:
    ViewPortWindow(QWidget *parent = nullptr);
    ~ViewPortWindow();

private:
    Ui::ViewPortWindowClass ui;
};
