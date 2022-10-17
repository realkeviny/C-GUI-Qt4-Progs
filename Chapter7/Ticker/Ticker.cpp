#include "Ticker.h"
#include <QtWidgets>

Ticker::Ticker(QWidget *parent)
    : QWidget(parent)
{
    offset = 0;
    myTimerId = 0; //定时器未启动
}

void Ticker::setText(const QString& newText)
{
    myText = newText;
    update();
    updateGeometry();
}

QSize Ticker::sizeHint() const
{
    return fontMetrics().size(0,text());
}

void Ticker::paintEvent(QPaintEvent* /*event*/)
{
    QPainter painter(this);

    int textWidth = fontMetrics().width(text());//确定文本在水平方向上所需要的空间
    if(textWidth < 1)
    {
        return;
    }
    int x = -offset;
    while(x < width())
    {
        painter.drawText(x,0,textWidth,height(),Qt::AlignLeft | Qt::AlignVCenter,text());//文本绘制
        x += textWidth;
    }
}

void Ticker::showEvent(QShowEvent* /*event*/)
{
    myTimerId = startTimer(30);
}

void Ticker::timerEvent(QTimerEvent* event)
{
    if(event->timerId() == myTimerId)
    {
        ++offset;
        if(offset >= fontMetrics().width(text()))
        {
            offset = 0;
        }
        scroll(-1,0);
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void Ticker::hideEvent(QHideEvent* /*event*/)
{
    killTimer(myTimerId);
    myTimerId = 0;
}


