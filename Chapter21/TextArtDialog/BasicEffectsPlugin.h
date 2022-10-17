#ifndef BASICEFFECTPLUGIN_H
#define BASICEFFECTPLUGIN_H

#include "basiceffectsplugin_global.h"
#include <QObject>

class BASICEFFECTSPLUGIN_EXPORT BasicEffectsPlugin:public QObject,public TextArtInterface
{
	Q_OBJECT
	Q_INTERFACES(TextArtInterface)

public:
	QStringList effects() const;
	QPixmap applyEffect(const QString& effect, const QString& text, const QFont& font, const QSize& size, const QPen& pen, const QBrush& brush);
};

#endif