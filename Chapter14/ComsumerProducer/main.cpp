#include <QtCore>
#include <iostream>

constexpr int DataSize = 10;
constexpr int BufferSize = 4;
char buffer[BufferSize];

QSemaphore freeSpace(BufferSize);
QSemaphore usedSpace(0);
class Producer : public QThread
{
public:
    void run() override;
};

void Producer::run()
{
	for (int i = 0; i < DataSize; ++i)
	{
		freeSpace.acquire();
		buffer[i % BufferSize] = "Pc"[static_cast<uint>(std::rand()) % 4];
		usedSpace.release();
	}
}

class Consumer:public QThread
{
public:
	void run() override;
};

void Consumer::run()
{
	for (int i = 0; i < DataSize; ++i)
	{
		usedSpace.acquire();
		std::cerr << buffer[i % BufferSize];
		freeSpace.release();
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
