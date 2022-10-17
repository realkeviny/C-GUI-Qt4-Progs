#ifndef BRONZESTYLEPLUGIN_H
#define BRONZESTYLEPLUGIN_H

#include <QtWidgets/QStylePlugin>

class BronzeStylePlugin  : public QStylePlugin
{
	Q_OBJECT
public:
	QStringList keys() const;
	QStyle* create(const QString& key);
};

#endif