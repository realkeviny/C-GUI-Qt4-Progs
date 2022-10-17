#include "PrintWindow.h"
#include <QPrintDialog>

PrintWindow::PrintWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void PrintWindow::printImage(const QImage& image)
{
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec())
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0, 0, image);
    }
}


