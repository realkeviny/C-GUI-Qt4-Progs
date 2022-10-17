#include "Node.h"
#include "Link.h"

#include <QtWidgets>

Node::Node()
{
	myTextColor = Qt::darkGreen;
	myOutlineColor = Qt::darkBlue;
	myBackgroundColor = Qt::white;

	setFlags(ItemIsMovable | ItemSendsGeometryChanges | ItemIsSelectable);
}

Node::~Node()
{
	foreach(Link* link,myLinks)
	{
		delete link;
	}
}

void Node::setText(const QString& text)
{
	prepareGeometryChange();
	myText = text;
	update();
}

QString Node::text() const
{
	return myText;
}

void Node::setTextColor(const QColor& color)
{
	myTextColor = color;
	update();
}

QColor Node::textColor() const
{
	return myTextColor;
}

void Node::setOutlineColor(const QColor& color)
{
	myOutlineColor = color;
	update();
}

QColor Node::outlineColor() const
{
	return myOutlineColor;
}

void Node::setBackgroundColor(const QColor& color)
{
	myBackgroundColor = color;
	update();
}

QColor Node::backgroundColor() const
{
	return myBackgroundColor;
}

void Node::addLink(Link* link)
{
	myLinks.insert(link);
}

void Node::removeLink(Link* link)
{
	myLinks.remove(link);
}

QRectF Node::outlineRect() const
{
	constexpr  int Padding = 8;
	QFontMetricsF metrics = qApp->fontMetrics();
	QRectF rect = metrics.boundingRect(myText);
	rect.adjust(-Padding, -Padding, +Padding, +Padding);
	rect.translate(-rect.center());
	return rect;
}

QRectF Node::boundingRect() const
{
	constexpr  int Margin = 1;
	return outlineRect().adjusted(-Margin, -Margin, +Margin, +Margin);
}

QPainterPath Node::shape() const
{
	QRectF rect = outlineRect();

	QPainterPath path;
	path.addRoundedRect(rect, roundness(rect.width()), roundness(rect.height()));
	return path;
}

void Node::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QPen pen(myOutlineColor);
	if(option->state & QStyle::State_Selected)
	{
		pen.setStyle(Qt::DotLine);
		pen.setWidth(2);
	}
	painter->setPen(pen);
	painter->setBrush(myBackgroundColor);

	QRectF rect = outlineRect();
	painter->drawRoundedRect(rect, roundness(rect.width()), roundness(rect.height()));
	painter->setPen(myTextColor);
	painter->drawText(rect, Qt::AlignCenter, myText);
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant& value)
{
	if(change==ItemPositionHasChanged)
	{
		foreach(Link* link,myLinks)
		{
			link->trackNodes();
		}
	}
	return QGraphicsItem::itemChange(change, value);
}

void Node::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	QString text = QInputDialog::getText(event->widget(), tr("Edit Text:"), tr("Enter New Text:"), QLineEdit::Normal, myText);
	if(!text.isEmpty())
	{
		setText(text);
	}
}

int Node::roundness(double size) const
{
	constexpr int Diameter = 12;
	return 100 * Diameter / static_cast<int>(size);
}

