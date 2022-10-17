#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H


#include <QTableWidget>

class MyTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    MyTableWidget(QWidget *parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    QPoint startPos;
    void performDrag();
};

#endif