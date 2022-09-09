#include "Health.h"

Health::Health(qint16 level, SoldierType soldierType)
{
	mLevel = level;
}

void Health::incrementLevel()
{
	mLevel++;
}

quint16 Health::getLevel()
{
	return mLevel;
}

void Health::setCurrentHealth(qint16 newHealth)
{
	mCurrentHealth = newHealth;
}

qint16 Health::getCurrentHealth()
{
	return mCurrentHealth;
}

void Health::setCurrentArmor(qint16 newArmor)
{
	mCurrentArmor = newArmor;
}

qint16 Health::getCurrentArmor()
{
	return mCurrentArmor;
}

void Health::setMaxHealth(qint16 newHealth)
{
	mMaxHealth = newHealth;
}

qint16 Health::getMaxHealth()
{
	return mMaxHealth;
}

void Health::setMaxArmor(qint16 newArmor)
{
	mMaxArmor = newArmor;
}

qint16 Health::getMaxAmor()
{
	return mMaxArmor;
}

qint16 Health::getHealthModifier()
{
	qint16 health = 0;
	qint16 armor = 0;
	qint16 coeffHealth = 0;
	qint16 coeffArmor = 0;


	switch (mSoldierType) {
		case(SoldierType::Admiral) : {

			coeffHealth = 3;
			coeffArmor = 3;

			health = ((mLevel / 2) * coeffHealth) / 4 + 2;
			armor = ((mLevel / 2) * coeffArmor) / 4 + 2;

			break;
		}
		case(SoldierType::BattleDroid): {

			coeffHealth = 3;
			coeffArmor = 3;

			health = ((mLevel / 2) * coeffHealth) / 4 + 2;
			armor = ((mLevel / 2) * coeffArmor) / 4 + 2;

			break;
		}
	}
	return qint16();
}

qint16 Health::getArmorModifier()
{
	return qint16();
}


