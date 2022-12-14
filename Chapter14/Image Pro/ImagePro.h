#ifndef IMAGEPRO_H
#define IMAGEPRO_H

#include <QMainWindow>

class QAction;
class QLabel;
class QMenu;
#include "TransactionThread.h"

class ImagePro : public QMainWindow
{
    Q_OBJECT

public:
    ImagePro();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void open();
    bool save();
    bool saveAs();
    void flipHorizontally();
    void flipVertically();
	void resizeImage();
    void convertTo32Bit();
    void convertTo8Bit();
    void convertTo1Bit();
    void about();
    void allTransactionsDone();

private:
    void createActions();
    void createMenus();
    bool okToContinue();
    void loadFile(const QString& fileName);
    void saveFile(const QString& fileName);
    void setCurrentFile(const QString& fileName);
    QString strippedName(const QString& fullFileName);
    void addTransaction(Transaction* transact);

    TransactionThread thread;
    QLabel* imageLabel;
    QByteArray imageFormat;
    QString curFile;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* convertToSubMenu;
    QMenu* helpMenu;
    QAction* openAction;
    QAction* saveAction;
    QAction* saveAsAction;
    QAction* exitAction;
    QAction* flipHorizontalAction;
    QAction* flipVerticalAction;
    QAction* rotateAction;
    QAction* resizeAction;
    QAction* convertTo32BitAction;
    QAction* convertTo8BitAction;
    QAction* convertTo1BitAction;
    QAction* aboutAction;
    QAction* aboutQtAction;
};

#endif
