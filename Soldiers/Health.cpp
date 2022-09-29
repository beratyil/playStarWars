#include "Health.h"

Health::Health(qint16 level, SoldierType soldierType)
{
	mLevel = level;
	mSoldierType = soldierType;

	updateMaxDefense();

	fillHealth();
	fillArmor();
}

void Health::incrementLevel()
{
	mLevel++;

	updateMaxDefense();
}

quint16 Health::getLevel() const
{
	return mLevel;
}

void Health::setLevel(qint16 level)
{
	mLevel = level;
}

void Health::setCurrentHealth(qint16 newHealth)
{
	mCurrentHealth = newHealth;
}

qint16 Health::getCurrentHealth() const
{
	return mCurrentHealth;
}

void Health::setCurrentArmor(qint16 newArmor)
{
	mCurrentArmor = newArmor;
}

qint16 Health::getCurrentArmor() const
{
	return mCurrentArmor;
}

void Health::setMaxHealth(qint16 newHealth)
{
	mMaxHealth = newHealth;
}

qint16 Health::getMaxHealth() const
{
	return mMaxHealth;
}

void Health::setMaxArmor(qint16 newArmor)
{
	mMaxArmor = newArmor;
}

qint16 Health::getMaxArmor() const
{
	return mMaxArmor;
}

void Health::updateMaxDefense()
{
	qint16 health = 0;
	qint16 armor = 0;
	qint16 coeffHealth = 0;
	qint16 coeffArmor = 0;

	QMap<qint16, qint16> lut = coeffLut[mSoldierType];

	auto it = lut.begin();

	qint16 healthLevelCoeff = it.key();
	qint16 healthModifier = it.value();

	it++;

	qint16 armorLevelCoeff = it.key();
	qint16 armorModifier = it.value();

	mMaxHealth = ((mLevel / healthLevelCoeff) * healthModifier) / 4 + 2;
	mMaxArmor = ((mLevel / armorLevelCoeff) * armorModifier) / 4 + 2;
}

void Health::fillHealth()
{
	mCurrentHealth = mMaxHealth;
}

void Health::fillArmor()
{
	mCurrentArmor = mMaxArmor;
}

