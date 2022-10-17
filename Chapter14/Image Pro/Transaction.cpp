#include "Transaction.h"
#include <QtWidgets>

Transaction* const EndTransaction = nullptr;

FlipTransaction::FlipTransaction(Qt::Orientation orientation)
{
	this->orientation = orientation;
}

QImage FlipTransaction::apply(const QImage& image)
{
	return image.mirrored(orientation == Qt::Horizontal, orientation == Qt::Vertical);
}

QString FlipTransaction::message()
{
	if(orientation==Qt::Horizontal)
	{
		return QObject::tr("Flipping image horizontally...");
	}
	else
	{
		return QObject::tr("Flipping image vertically...");
	}
}

ResizeTransaction::ResizeTransaction(const QSize& size)
{
	this->size = size;
}

QString ResizeTransaction::message()
{
	return QObject::tr("Resizing image...");
}

QImage ResizeTransaction::apply(const QImage& image)
{
	return image.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

ConvertDepthTransaction::ConvertDepthTransaction(int depth)
{
	this->depth = depth;
}

QImage ConvertDepthTransaction::apply(const QImage& image)
{
	QImage::Format format;

	switch (depth)
	{
	case 1:
		format = QImage::Format_Mono;
		break;
	case 8:
		format = QImage::Format_Indexed8;
		break;
	case 24:
	default:
		format = QImage::Format_RGB32;
	}

	return image.convertToFormat(format);
}

QString ConvertDepthTransaction::message()
{
	return QObject::tr("Converting image depth...");
}


