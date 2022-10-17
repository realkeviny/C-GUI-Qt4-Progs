#include "MyTableWidget.h"
#include <QtWidgets>

MyTableWidget::MyTableWidget(QWidget *parent)
    : QTableWidget(parent)
{
    setAcceptDrops(true);
}

void MyTableWidget::mouseMoveEvent(QMouseEvent* event)
{
	if(event->buttons()&Qt::LeftButton)
	{
		int distance = (event->pos() - startPos).manhattanLength();
		if(distance>=QApplication::startDragDistance())
		{
			performDrag();
		}
	}
	QTableWidget::mouseMoveEvent(event);
}

void MyTableWidget::performDrag()
{
	QString plainText = selection 
}
