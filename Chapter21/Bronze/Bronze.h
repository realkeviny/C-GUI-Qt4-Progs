#ifndef BRONZESTYLE_H
#define BRONZESTYLE_H

#include <QCommonStyle>

class QRect;

class Bronze : public QCommonStyle
{
    Q_OBJECT

public:
    Bronze(){}

    void polish(QPalette& palette);
    void polish(QWidget* widget);
    void unpolish(QWidget* widget);
    int styleHint(StyleHint which, const QStyleOption* option, const QWidget* widget = nullptr, QStyleHintReturn* returnData = nullptr) const;
    int pixelMetric(PixelMetric which, const QStyleOption* option, const QWidget* widget = nullptr) const;
    void drawPrimitive(PrimitiveElement which, const QStyleOption* option, QPainter* painter, const QWidget* widget = nullptr) const;
    void drawComplexControl(ComplexControl which, const QStyleOptionComplex* option, QPainter* painter, const QWidget* widget = nullptr) const;
    QRect subControlRect(ComplexControl whichControl, const QStyleOptionComplex* option, SubControl whichSubControl, const QWidget* widget = nullptr) const;

public slots:
    QIcon standardIcon(StandardPixmap which, const QStyleOption* option, const QWidget* widget = nullptr) const;

private:
    void drawBronzeFrame(const QStyleOption* option, QPainter* painter) const;
    void drawBronzeBevel(const QStyleOption* option, QPainter* painter) const;
    void drawBronzeCheckBoxIndicator(const QStyleOption* option, QPainter* painter) const;
    void drawBronzeSpinBoxButton(SubControl which, const QStyleOptionComplex* option, QPainter* painter) const;
};

#endif