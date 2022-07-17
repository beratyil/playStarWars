#pragma once

#include "soldier_global.h"
#include "qstring.h"

namespace SoldierSpace
{
	enum Weapon {
		DC_15A_CARBINE,
		DC_15A_RIFLE,
		Z_6_ROTARY_CANON,
		DC_15X_SNIPER
	};

	class Damage
	{
	public:
		
		Damage();
		Damage(qint16 initDamage);

		qint16 operator = (qint16 damage);

		qint16 damage();

		void setDamage(qint16 damage);

	private:
		qint16 mCurrentDamage;
	};

	class CloneCommonSkill
	{
	public:
		CloneCommonSkill(qint16 closeRange, qint16 longRange);
		~CloneCommonSkill();

		qint16 blasterAttack();
		qint16 meleeAttack();

		void setBlasterDamage(qint16 newBlasterDamage);
		void setMeleeDamage(qint16 newMeleeDamage);

	private:
		Damage mLongRangeDamage;
		Damage mCloseRangeDamage;
	};

	class CloneSpecialSkill
	{
	public:
		CloneSpecialSkill(qint16 blaster, qint16 equipment);
		~CloneSpecialSkill();

		qint16 blasterAttack();
		qint16 equipmentAttack();

		void setBlasterDamage(qint16 newBlasterDamage);
		void setEquipmentDamage(qint16 newMeleeDamage);

	private:
		Damage mBlasterSpecialDamage;
		Damage mEquipmentSpecialDamage;
	};
	

};
