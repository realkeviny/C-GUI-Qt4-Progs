#include "TransactionThread.h"
#include <QMutexLocker>

Transaction* const EndTransaction = nullptr;

TransactionThread::TransactionThread()
{
	start();
}


TransactionThread::~TransactionThread()
{
	{
		QMutexLocker locked(&mutex);
		while (!transactions.isEmpty())
		{
			delete transactions.dequeue();
		}
		transactions.enqueue(EndTransaction);
		transactionAdded.wakeOne();
	}
	wait();
}

void TransactionThread::addTransaction(Transaction* transact)
{
	QMutexLocker locker(&mutex);
	transactions.enqueue(transact);
	transactionAdded.wakeOne();
}

void TransactionThread::setImage(const QImage& image)
{
	QMutexLocker locker(&mutex);
	currentImage = image;
}

QImage TransactionThread::image()
{
	QMutexLocker locker(&mutex);
	return currentImage;
}

void TransactionThread::run()
{
	Transaction* transact = nullptr;
	QImage oldImage;

	forever
	{
		{
			QMutexLocker locker(&mutex);

			if(transactions.isEmpty())
			{
				transactionAdded.wait(&mutex);
			}
			transact = transactions.dequeue();
			if(transact==EndTransaction)
			{
				break;
			}

			oldImage = currentImage;
		}
		emit transactionStarted(transact->message());
		QImage newImage = transact->apply(oldImage);
		delete transact;

		{
			QMutexLocker locker(&mutex);
			currentImage = newImage;
			if(transactions.isEmpty())
			{
				emit allTransactionsDone();
			}
		}
	}
}