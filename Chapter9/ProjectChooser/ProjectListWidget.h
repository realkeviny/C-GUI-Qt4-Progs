#ifndef PROJECTLISTWIDGET_H
#define PROJECTLISTWIDGET_H

#include <QListWidget>

class ProjectListWidget  : public QListWidget
{
	Q_OBJECT

public:
	ProjectListWidget(QWidget *parent);

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void dropEvent(QDropEvent* event) override;

private:
	void performDrag();
	QPoint startPos;
};

#endif