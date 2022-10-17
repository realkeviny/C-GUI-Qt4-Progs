#ifndef DRAGEXAMPLE_H
#define DRAGEXAMPLE_H

#include <QMainWindow>
#include "ui_DragExample.h"

class QTextEdit;

QT_BEGIN_NAMESPACE
namespace Ui { class DragExampleClass; };
QT_END_NAMESPACE

class DragExample : public QMainWindow
{
    Q_OBJECT

public:
    DragExample(QWidget *parent = nullptr);
    ~DragExample();

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
private:
    Ui::DragExampleClass *ui;
    bool readFile(const QString& fileName);
    QTextEdit* textEdit;
};

#endif