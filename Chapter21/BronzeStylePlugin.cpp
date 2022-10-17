#include "BronzeStylePlugin.h"
#include "../Bronze/Bronze.h"

QStringList BronzeStylePlugin::keys() const
{
	return QStringList() << "Bronze";
}

QStyle* BronzeStylePlugin::create(const QString& key)
{
	if (key.toLower() == "bronze")
	{
		return new Bronze;
	}
	return 0;
}

Q_PLUGIN_METADATA(IID "Bronze_Plugin" FILE "Bronze.json")
