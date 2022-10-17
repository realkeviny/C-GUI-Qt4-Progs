#ifndef NODE_H
#define NODE_H

#include <QApplication>
#include <QGraphicsItem>
#include <QColor>
#include <QSet>

class Link;

class Node :
    public QGraphicsItem
{
    Q_DECLARE_TR_FUNCTIONS(Node)

public:
    Node();
    ~Node();
    void setText(const QString& text);
    QString text() const;
    void setTextColor(const QColor& color);
    QColor textColor() const;
    void setOutlineColor(const QColor& color);
    QColor outlineColor() const;
    void setBackgroundColor(const QColor& color);
    QColor backgroundColor() const;
    void addLink(Link* link);
    void removeLink(Link* link);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

private:
    QRectF outlineRect() const;
    int roundness(double size) const;

    QSet<Link*> myLinks;
    QString myText;
    QColor myTextColor;
    QColor myBackgroundColor;
    QColor myOutlineColor;
};

#endif