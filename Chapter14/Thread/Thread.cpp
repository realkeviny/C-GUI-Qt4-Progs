#include "Thread.h"

#include <iostream>
#include <QMutexLocker>

Thread::Thread()
{
	stopped = false;
}

void Thread::run()
{
	forever
	{
		{
			QMutexLocker locker(&mutex);
			if(stopped)
			{
				stopped = false;
				break;
			}
		}
		std::cerr << qPrintable(messageStr);
	}
	std::cerr << std::endl;
}

void Thread::stop()
{
	QMutexLocker locker(&mutex);
	stopped = true;
}

void Thread::setMessage(const QString& message)
{
	messageStr = message;
}

