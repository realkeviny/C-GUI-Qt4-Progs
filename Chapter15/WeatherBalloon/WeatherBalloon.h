#ifndef WEATHERBALLOON_H
#define WEATHERBALLOON_H

#include <QPushButton>
#include <QUdpSocket>
#include <QTimer>

class WeatherBalloon : public QPushButton
{
    Q_OBJECT

public:
    WeatherBalloon(QWidget *parent = nullptr);
    double temperature() const;
    double humidity() const;
    double altitude() const;

private slots:
    void sendDatagram();
private:
    QUdpSocket udpSocket;
    QTimer timer;
};

#endif