#pragma once
#include <qstring.h>

class EnemyDatabase
{
public:
	EnemyDatabase(qint16, QString, QString, qint16, bool);

	qint16 getIndex();
	QString getImageLocation();
	QString getSoldierType();
	bool isMirrored();
	qint16 getLevel();

private:
	qint16 mIndex;
	QString mImageLocation;
	QString mSoldierTypeStr;
	qint16 mLevel;
	bool mIsMirrored;
};