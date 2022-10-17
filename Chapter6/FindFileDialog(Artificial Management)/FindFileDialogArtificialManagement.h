#ifndef FINDFILEDIALOG_H
#define FINDFILEDIALOG_H

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;

class FindFileDialogArtificialManagement : public QDialog
{
    Q_OBJECT

public:
    FindFileDialogArtificialManagement(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QLabel* namedLabel;
    QLabel* lookInLabel;
    QLineEdit* lookInLineEdit;
    QLineEdit* namedLineEdit;
    QCheckBox* subfoldersCheckBox;
    QTableWidget* tableWidget;
    QLabel* messageLabel;
    QPushButton* findButton;
    QPushButton* stopButton;
    QPushButton* closeButton;
    QPushButton* helpButton;
};

#endif