#include "WeatherBalloon.h"

#include <qdatetime.h>

WeatherBalloon::WeatherBalloon(QWidget *parent)
    : QPushButton(tr("Quit"), parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(close()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(sendDatagram()));

    timer.start(2 * 1000);
    setWindowTitle(tr("Weather Balloon"));
}

void WeatherBalloon::sendDatagram()
{
    QByteArray dataGram;
    QDataStream out(&dataGram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);
    out << QDateTime::currentDateTime() << temperature() << humidity() << altitude();
    udpSocket.writeDatagram(dataGram, QHostAddress::LocalHost, 5824);
}

double WeatherBalloon::temperature() const
{
    return -20.0 + (2.0 * std::rand() / (RAND_MAX + 1.0));
}

double WeatherBalloon::humidity() const
{
    return -20.0 + (2.0 * std::rand() / (RAND_MAX + 1.0));

}

double WeatherBalloon::altitude() const
{
    return -20.0 + (2.0 * std::rand() / (RAND_MAX + 1.0));
}

