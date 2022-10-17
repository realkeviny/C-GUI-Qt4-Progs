#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QtWidgets>
#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class finddialog : public QDialog
{
    Q_OBJECT

public:
    finddialog(QWidget *parent = nullptr);
    ~finddialog();

	signals:
        void findNext(const QString& str, Qt::CaseSensitivity cs);
        void findPrevious(const QString& str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindbutton(const QString& text);
private:
    QLabel* label;
    QLineEdit* lineEdit;
    QCheckBox* caseCheckBox;
    QCheckBox* backwardCheckBox;
    QPushButton* findButton;
    QPushButton* closeButton;
};

#endif
