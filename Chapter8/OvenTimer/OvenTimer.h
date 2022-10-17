#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QtWidgets>
#include "ui_OvenTimer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OvenTimerClass; };
QT_END_NAMESPACE

class OvenTimer : public QWidget
{
    Q_OBJECT

public:
    OvenTimer(QWidget *parent = nullptr);
    ~OvenTimer();

    void setDuration(int secs);
    int duration() const;
    void draw(QPainter* painter);


signals:
    void timeout();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
private:
    Ui::OvenTimerClass *ui;
    QDateTime finishTime;
    QTimer* updateTimer;
    QTimer* finishTimer;
};

#endif