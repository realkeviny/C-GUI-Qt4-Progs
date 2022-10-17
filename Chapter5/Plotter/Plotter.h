#ifndef PLOTTER_H
#define PLOTTER_h

#include <QWidget>
#include <QMap>
#include <QVector>
#include <QPixmap>
#include <QToolButton>
#include "PlotSettings.h"

class QToolButton;
class PlotSettings;

class Plotter : public QWidget
{
    Q_OBJECT

public:
    Plotter(QWidget *parent = nullptr);

    void setPlotSettings(const PlotSettings& settings);
    void setCurveData(int id, const QVector<QPointF>& data);
    void clearCurve(int id);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:
    void updateRubberBandRegion();
    void refreshPixmap();
    void drawGrid(QPainter* painter);
    void drawCurves(QPainter* painter);

    enum{Margin=50};

    QToolButton* zoomInButton;
    QToolButton* zoomOutButton;
    QMap<int, QVector<QPointF>> curveMap;
    QVector<PlotSettings> zoomStack;
    int curZoom;
    bool rubberBandIsShown;
    QRect rubberBandRect;
    QPixmap pixmap;
    
};

#endif