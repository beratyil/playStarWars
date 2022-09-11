#pragma once
#include <qstring.h>

class EnemyDatabase
{
public:
	EnemyDatabase(quint16, QString, QString, qint16, bool);

	quint16 getIndex();
	QString getImageLocation();
	QString getSoldierType();
	bool isMirrored();
	qint16 getLevel();

private:
	quint16 mIndex;
	QString mImageLocation;
	QString mSoldierTypeStr;
	qint16 mLevel;
	bool mIsMirrored;
};