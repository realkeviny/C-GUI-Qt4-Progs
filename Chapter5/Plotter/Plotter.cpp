#include "Plotter.h"

#include <QMouseEvent>

#include <QStylePainter>
#include <QStyleOptionFocusRect>

Plotter::Plotter(QWidget* parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);
    rubberBandIsShown = false;

    zoomInButton = new QToolButton(this);
    zoomInButton->setIcon(QIcon(":/Plotter/image/ZoomIn.png"));
    zoomInButton->adjustSize();
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));

    zoomOutButton = new QToolButton(this);
    zoomOutButton->setIcon(QIcon(":/Plotter/image/ZoomOut.png"));
    zoomOutButton->adjustSize();
    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));

    setPlotSettings(PlotSettings());
}

void Plotter::setPlotSettings(const PlotSettings& settings)
{
    zoomStack.clear();
    zoomStack.append(settings);
    curZoom = 0;
    zoomInButton->hide();
    zoomOutButton->hide();
    refreshPixmap();
}

void Plotter::zoomOut()
{
	if(curZoom > 0)
	{
        --curZoom;
        zoomOutButton->setEnabled(curZoom > 0);
        zoomInButton->setEnabled(true);
        zoomInButton->show();
        refreshPixmap();
	}
}

void Plotter::zoomIn()
{
	if(curZoom <zoomStack.count() -1)
	{
        ++curZoom;
        zoomInButton->setEnabled(curZoom < zoomStack.count() - 1);
        zoomOutButton->setEnabled(true);
        zoomOutButton->show();
        refreshPixmap();
	}
}

void Plotter::setCurveData(int id, const QVector<QPointF>& data)
{
    curveMap[id] = data;
    refreshPixmap();
}

void Plotter::clearCurve(int id)
{
    curveMap.remove(id);
    refreshPixmap();
}

QSize Plotter::minimumSizeHint() const
{
    return QSize(6 * Margin, 4 * Margin);
}

QSize Plotter::sizeHint() const
{
    return QSize(12 * Margin, 8 * Margin);
}

void Plotter::paintEvent(QPaintEvent* event)
{
    QStylePainter painter(this);
    painter.drawPixmap(0, 0, pixmap);

    if(rubberBandIsShown)
    {
        painter.setPen(palette().light().color());
        painter.drawRect(rubberBandRect.normalized().adjusted(0, 0, -1, -1));
    }
    if(hasFocus())
    {
        QStyleOptionFocusRect option;
        option.initFrom(this);
        option.backgroundColor = palette().dark().color();
        painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);
    }
}

void Plotter::resizeEvent(QResizeEvent* event)
{
    int x = width() - (zoomInButton->width() + zoomOutButton->width() + 10);
    zoomInButton->move(x, 5);
    zoomOutButton->move(x + zoomInButton->width() + 5, 5);
    refreshPixmap();
}

void Plotter::mousePressEvent(QMouseEvent* event)
{
    QRect rect(Margin, Margin, width() - 2 * Margin, height() - 2 * Margin);

    if(event->button() == Qt::LeftButton)
    {
	    if(rect.contains(event->pos()))
	    {
            rubberBandIsShown = true;
            rubberBandRect.setTopLeft(event->pos());
            rubberBandRect.setBottomRight(event->pos());
            updateRubberBandRegion();
            setCursor(Qt::CrossCursor);
	    }
    }
}

void Plotter::mouseMoveEvent(QMouseEvent* event)
{
	if(rubberBandIsShown)
	{
        updateRubberBandRegion();
        rubberBandRect.setBottomRight(event->pos());
        updateRubberBandRegion();
	}
}

void Plotter::mouseReleaseEvent(QMouseEvent* event)
{
	if((event->button() == Qt::LeftButton) && rubberBandIsShown)
	{
        rubberBandIsShown = false;
        updateRubberBandRegion();
        unsetCursor();

        QRect rect = rubberBandRect.normalized();
        if(rect.width()<4 || rect.height()<4)
        {
	        return;
        }
        rect.translate(-Margin, -Margin);

        PlotSettings prevSettings = zoomStack[curZoom];
        PlotSettings settings;
        double dx = prevSettings.spanX() / (width() - 2 * Margin);
        double dy = prevSettings.spanY() / (height() - 2 * Margin);
        settings.minX = prevSettings.minX + dx * rect.left();
        settings.maxX = prevSettings.minX + dx * rect.right();
        settings.minY = prevSettings.minY + dy * rect.bottom();
        settings.maxY = prevSettings.minY + dy * rect.top();
        settings.adjust();

        zoomStack.resize(curZoom + 1);
        zoomStack.append(settings);
        zoomIn();
	}
}

void Plotter::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Plus:
        zoomIn();
        break;
	case Qt::Key_Minus:
        zoomOut();
        break;
	case Qt::Key_Left:
        zoomStack[curZoom].scroll(-1, 0);
        refreshPixmap();
        break;
	case Qt::Key_Right:
        zoomStack[curZoom].scroll(+1, 0);
        refreshPixmap();
        break;
	case Qt::Key_Down:
        zoomStack[curZoom].scroll(0, -1);
        refreshPixmap();
        break;
	case Qt::Key_Up:
        zoomStack[curZoom].scroll(0, +1);
        refreshPixmap();
        break;
	default:
        QWidget::keyPressEvent(event);
	}
}

void Plotter::wheelEvent(QWheelEvent* event)
{
    int numDegrees = event->delta() / 8;
    int numTicks = numDegrees / 15;

    if(event->orientation() == Qt::Horizontal)
    {
        zoomStack[curZoom].scroll(numTicks, 0);
    }
    else
    {
        zoomStack[curZoom].scroll(0, numTicks);
    }
    refreshPixmap();
}

void Plotter::updateRubberBandRegion()
{
    QRect rect = rubberBandRect.normalized();
    update(rect.left(), rect.top(), rect.width(), 1);
    update(rect.left(), rect.top(), 1, rect.height());
    update(rect.left(), rect.bottom(), rect.width(), 1);
    update(rect.right(), rect.top(), 1, rect.height());
}

void Plotter::refreshPixmap()
{
    pixmap = QPixmap(size());
    pixmap.fill(this, 0, 0);

    QPainter painter(&pixmap);
    painter.initFrom(this);
    drawGrid(&painter);
    drawCurves(&painter);
    update();
}

void Plotter::drawGrid(QPainter* painter)
{
    QRect rect(Margin, Margin, width() - 2 * Margin, height() - 2 * Margin);
    if(!rect.isValid())
        return;

    PlotSettings settings = zoomStack[curZoom];
    QPen quiteDark = palette().dark().color().light();
    QPen light = palette().light().color();

    for (int i = 0; i <= settings.numXTicks; ++i)//�����ߡ���x�������ϵı�Ƿ�
    {
        int x = rect.left() + (i * (rect.width() - 1) / settings.numXTicks);
        double label = settings.minX + (i * settings.spanX() / settings.numXTicks);

        painter->setPen(quiteDark);
        painter->drawLine(x, rect.top(), x, rect.bottom());
        painter->setPen(light);
        painter->drawLine(x, rect.bottom(), x, rect.bottom() + 5);
        painter->drawText(x - 50, rect.bottom() + 5, 100, 2, Qt::AlignHCenter | Qt::AlignTop, QString::number(label));
    }
    for (int j = 0; j <= settings.numYTicks; ++j)//��������ˮƽ�ߺ���y�����ϱ�Ƿ�
    {
        int y = rect.bottom() - (j * (rect.height() - 1) / settings.numYTicks);
        double label = settings.minY + (j * settings.spanY() / settings.numYTicks);
        painter->setPen(quiteDark);
        painter->drawLine(rect.left(), y, rect.right(), y);
        painter->setPen(light);
        painter->drawLine(rect.left() - 5, y, rect.left(), y);
        painter->drawText(rect.left() - Margin, y - 10, Margin - 5, 20, Qt::AlignRight | Qt::AlignVCenter, QString::number(label));
    }
    painter->drawRect(rect.adjusted(0, 0, -1, -1));
}

void Plotter::drawCurves(QPainter* painter)
{
    static const QColor colorForIds[6] = { Qt::red,Qt::green,Qt::cyan,Qt::magenta,Qt::yellow };
    PlotSettings settings = zoomStack[curZoom];
    QRect rect{ Margin,Margin,width() - 2 * Margin,height() - 2 * Margin };
    if(!rect.isValid())
    {
        return;
    }
    painter->setClipRect(rect.adjusted(+1, +1, -1, -1));

    QMapIterator<int, QVector<QPointF> > i(curveMap);
    while (i.hasNext())
    {
        i.next();

        int id = i.key();
        QVector<QPointF> data = i.value();
        QPolygonF polyline(data.count());
        for (int j = 0; j < data.count(); ++j)
        {
            double dx = data[j].x() - settings.minX;
            double dy = data[j].y() - settings.minY;
            double x = rect.left() + (dx * (rect.width() - 1) / settings.spanX());
            double y = rect.bottom() - (dy * (rect.height() - 1) / settings.spanY());
            polyline[j] = QPointF(x, y);
        }
        painter->setPen(colorForIds[uint(id) % 6]);
        painter->drawPolyline(polyline);
    }
}
