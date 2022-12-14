#include <iostream>
#include <QtCore>
#include <QWaitCondition>

constexpr int DataSize = 100000;
constexpr int BufferSize = 4096;
char buffer[BufferSize];

QWaitCondition bufferIsNotFull;
QWaitCondition bufferIsNotEmpty;
QMutex mutex;
int usedSpace = 0;

class Producer : public QThread
{
public:
    void run() override;
};

void Producer::run()
{
	for (int i = 0; i < DataSize; ++i)
	{
		mutex.lock();
		while(usedSpace==BufferSize)
		{
			bufferIsNotFull.wait(&mutex);
		}
		//if(usedSpace==BufferSize)
		//{
		//	mutex.unlock();
		//	bufferIsNotFull.wait();
		//	mutex.lock();
		//}
		buffer[i % BufferSize] = "ACGT"[static_cast<uint>(std::rand()) % 4];
		++usedSpace;
		bufferIsNotEmpty.wakeAll();
		mutex.unlock();
	}
}

class Consumer : public QThread
{
public:
	void run() override;
};

void Consumer::run()
{
	for (int i = 0; i < DataSize; ++i)
	{
		mutex.lock();
		while(usedSpace==0)
		{
			bufferIsNotEmpty.wait(&mutex);
		}
		std::cerr << buffer[i % BufferSize];
		--usedSpace;
		bufferIsNotFull.wakeAll();
		mutex.unlock();
	}
	std::cerr << std::endl;
}

int main(int argc, char *argv[])
{
	Producer producer;
	Consumer consumer;
	producer.start();
	consumer.start();
	producer.wait();
	consumer.wait();
	return 0;
}
