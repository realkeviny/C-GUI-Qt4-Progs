#ifndef CITYSCAPE_H
#define CITYSCAPE_H

#include <QMainWindow>

class QGraphicsScene;
class CityView;

class CityScape : public QMainWindow
{
    Q_OBJECT

public:
    CityScape();

private:
    void generateCityBlocks();

    QGraphicsScene* scene;
    CityView* view;
};

#endif