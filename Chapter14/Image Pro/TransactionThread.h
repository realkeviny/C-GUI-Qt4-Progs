#ifndef TRANSACTIONTHREAD_H
#define TRANSACTIONTHREAD_H

#include <QThread>
#include <QQueue>
#include <QWaitCondition>
#include <QMutex>
#include "Transaction.h"

class TransactionThread :
    public QThread
{
    Q_OBJECT

public:
    TransactionThread();
    ~TransactionThread();

    void addTransaction(Transaction* transact);
    void setImage(const QImage& image);
    QImage image();

    signals:
        void transactionStarted(const QString& message);
        void allTransactionsDone();
protected:
    void run() override;

private:
    QImage currentImage;
    QQueue<Transaction*> transactions;
    QWaitCondition transactionAdded;
    QMutex mutex;
};

#endif