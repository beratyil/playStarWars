#pragma once

#include "qstring.h"
#include "qmap.h"

namespace SoldierSpace
{
	typedef qint16 (*SkillFunction)();

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

	class CloneWeapon
	{
	public:

		enum Weapon {
			DC_15A_CARBINE,
			DC_15A_RIFLE,
			Z_6_ROTARY_CANON,
			DC_15X_SNIPER
		};

		CloneWeapon(Weapon newWeapon);
		~CloneWeapon();

		void setWeapon(Weapon newWeapon);
		Weapon getWeapon();

		QString WeaponString();

		qint16 getWeaponDamage();

	private:
		Weapon weapon;
		Damage weaponDamage;

		QMap<Weapon, qint16> WeaponDamageMap{
			{DC_15A_CARBINE, 2},
			{DC_15A_RIFLE, 3},
			{Z_6_ROTARY_CANON, 5},
			{DC_15X_SNIPER, 4}
		};

	};

	class CloneCommonSkill
	{
	public:

		enum CommonSkill {
			BLASTERATTACK,
			MELEEATTACK
		};

		CloneCommonSkill(qint16 closeRange, qint16 longRange);
		~CloneCommonSkill();

		qint16 blasterAttack();
		qint16 meleeAttack();

		void setBlasterDamage(qint16 newBlasterDamage);
		void setMeleeDamage(qint16 newMeleeDamage);

		QMap<CommonSkill, SkillFunction> getSkills(); // Qnote: getSkill map as function pointers

	private:
		Damage mLongRangeDamage;
		Damage mCloseRangeDamage;

		QMap<CommonSkill, SkillFunction> skillMap;
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
