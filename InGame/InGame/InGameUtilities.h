#pragma once
#include <qstring.h>

class EnemyDatabase
{
public:
	EnemyDatabase(quint16, QString, QString, bool);

	quint16 getIndex();
	QString getImageLocation();
	QString getSoldierType();
	bool isMirrored();

private:
	quint16 mIndex;
	QString mImageLocation;
	QString mSoldierTypeStr;
	bool mIsMirrored;
};