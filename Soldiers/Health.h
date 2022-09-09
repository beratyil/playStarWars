#pragma once

#include <QtCore>
#include "Soldier.h"

typedef Soldier::SoldierType SoldierType;

class Health {
	public:
		Health(qint16 level, SoldierType soldierType);

		void incrementLevel();
		quint16 getLevel();

		void setCurrentHealth(qint16 newHealth);
		qint16 getCurrentHealth();

		void setCurrentArmor(qint16 newArmor);
		qint16 getCurrentArmor();

		void setMaxHealth(qint16 newHealth);
		qint16 getMaxHealth();

		void setMaxArmor(qint16 newArmor);
		qint16 getMaxAmor();

	private:

		qint16 getHealthModifier();
		qint16 getArmorModifier();

		qint16 mCurrentHealth;
		qint16 mCurrentArmor;
		quint16 mLevel;

		qint16 mMaxHealth;
		qint16 mMaxArmor;

		SoldierType mSoldierType;
};
