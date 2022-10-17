#include "MyWidget.h"
#include <QtWidgets>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    draw(&painter);
}

MyWidget::~MyWidget()
{}


void MyWidget::paintEvent(QPaintEvent* event)
{
    QLinearGradient gradient(50, 100, 300, 350);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(0.2, Qt::green);
    gradient.setColorAt(1.0, Qt::black);

}
