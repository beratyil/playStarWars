#pragma once

#include <QtCore>
#include "Soldier.h"

typedef Soldier::SoldierType SoldierType;

class Health {
	public:
		Health(qint16 level, SoldierType soldierType);

		void incrementLevel();
		quint16 getLevel() const;
		void setLevel(qint16 level);

		void setCurrentHealth(qint16 newHealth);
		qint16 getCurrentHealth() const;

		void setCurrentArmor(qint16 newArmor);
		qint16 getCurrentArmor() const;

		void setMaxHealth(qint16 newHealth);
		qint16 getMaxHealth() const;

		void setMaxArmor(qint16 newArmor);
		qint16 getMaxAmor() const;

	private:
		/*
		* Adjusts character balances
		* Update health and armor equation here
		*/
		void updateMaxDefense();

		qint16 mCurrentHealth;
		qint16 mCurrentArmor;
		quint16 mLevel;

		qint16 mMaxHealth;
		qint16 mMaxArmor;

		SoldierType mSoldierType;
		
		/*
		* Health and armor coefficients
		* The first map element for health
		* The second map element for armor
		* Look for updateMaxDefense() for equation
		*/
		QMap<SoldierType, QMap<qint16, qint16> > coeffLut 
		{
			{SoldierType::Admiral, { {2,2}, {3,2} } },
			{SoldierType::BattleDroid, { {2,2}, {3,2} } },
			{SoldierType::B2, { {2,2}, {3,2} } },
			{SoldierType::Commando, { {2,2}, {3,2} } },
			{SoldierType::Droideka, { {2,2}, {3,2} } },
			{SoldierType::Grevious_Guard, { {2,2}, {3,2} } },
			{SoldierType::IG_11, { {2,2}, {3,2} } },
			{SoldierType::Assault, { {2,2}, {3,2} } },
			{SoldierType::Heavy_Assault, { {2,2}, {3,2} } },
			{SoldierType::Sniper, { {2,2}, {3,2} } },
			{SoldierType::Commander, { {2,2}, {3,2} } },
			{SoldierType::Jedi_Padawan, { {2,4}, {2,4} } },
			{SoldierType::Jedi_Knight, { {2,5}, {2,6} } },
			{SoldierType::Jedi_Master, { {2,6}, {2,5} } },
			{SoldierType::Sith_Apprentice, { {2,5}, {2,5} } },
			{SoldierType::Sith_Master, { {2,5}, {2,6} } },
		};
};
