#include "InGameUtilities.h"

EnemyDatabase::EnemyDatabase(quint16 index, QString image, QString soldierType, bool isMirrored)
{
	mIndex = index;
	mImageLocation = image;
	mSoldierTypeStr = soldierType;
	mIsMirrored = isMirrored;
}

quint16 EnemyDatabase::getIndex()
{
	return mIndex;
}

QString EnemyDatabase::getImageLocation()
{
	return mImageLocation;
}

QString EnemyDatabase::getSoldierType()
{
	return mSoldierTypeStr;
}

bool EnemyDatabase::isMirrored()
{
	return mIsMirrored;
}
