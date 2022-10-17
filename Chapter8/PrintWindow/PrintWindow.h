#pragma once

#include <QtWidgets>
#include <QtPrintSupport/QPrinter>
#include "ui_PrintWindow.h"

class PrintWindow : public QMainWindow
{
    Q_OBJECT

public:
    PrintWindow(QWidget *parent = nullptr);
    void printImage(const QImage& image);

private:
    Ui::PrintWindowClass ui;
    QPrinter printer;
};
