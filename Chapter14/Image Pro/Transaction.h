#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QImage>


class Transaction
{
public:
	virtual ~Transaction(){}
	virtual QImage apply(const QImage& image) = 0;
	virtual QString message() = 0;
};

class FlipTransaction:public Transaction
{
public:
	FlipTransaction(Qt::Orientation orientation);

	QImage apply(const QImage& image) override;
	QString message() override;

private:
	Qt::Orientation orientation;
};

class ResizeTransaction : public Transaction
{
public:
	ResizeTransaction(const QSize& size);

	QImage apply(const QImage& image) override;
	QString message() override;

private:
	QSize size;
};

class ConvertDepthTransaction : public Transaction
{
public:
	ConvertDepthTransaction(int depth);

	QImage apply(const QImage& image) override;
	QString message() override;

private:
	int depth;
};


#endif