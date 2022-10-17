#ifndef CITYBLOCK_H
#define CITYBLOCK_H

#include <QGraphicsItem>

class CityBlock :
	public QGraphicsItem
{
public:
	enum Kind
	{
		Park, SmallBuilding, Hospital, Hall, Building, Tower, LShapedBlock, LShapedBlockPlusSmallBlock, TwoBlocks, BlockPlusTwoSmallBlocks
	};
	CityBlock(Kind kind);

	QRectF boundingRect() const;
	void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget);

private:
	int kind;
	QColor color;
	QPainterPath shape;

};


#endif