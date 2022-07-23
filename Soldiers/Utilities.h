#pragma once

#include "qstring.h"
#include "qmap.h"

namespace SoldierSpace
{

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

		enum class Weapon {
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
			{Weapon::DC_15A_CARBINE, 2},
			{Weapon::DC_15A_RIFLE, 3},
			{Weapon::Z_6_ROTARY_CANON, 5},
			{Weapon::DC_15X_SNIPER, 4}
		};

	};


	class CloneCommonSkill
	{

	public:
		typedef qint16(CloneCommonSkill::* SkillFunction)();

		enum class CommonSkill {
			blasterAttack,
			meleeAttack
		};

		CloneCommonSkill(qint16 closeRange, qint16 longRange);
		~CloneCommonSkill();

		qint16 blasterAttack();
		qint16 meleeAttack();

		void setBlasterDamage(qint16 newBlasterDamage);
		void setMeleeDamage(qint16 newMeleeDamage);

		QMap<CommonSkill, SkillFunction> getSkills(); // @note: getSkill map as function pointers
		
		// @note: this functions will be used after level up and new skill unlocked
		void addSkill(CloneCommonSkill::CommonSkill newSkillName, CloneCommonSkill::SkillFunction newSkill);

	private:
		Damage mLongRangeDamage;
		Damage mCloseRangeDamage;

		QMap<CommonSkill, SkillFunction> skillLut{
			{CommonSkill::blasterAttack, &CloneCommonSkill::blasterAttack},
			{CommonSkill::meleeAttack, &CloneCommonSkill::meleeAttack}
		};

	};


	class CloneSpecialSkill
	{
	public:
		
		enum class SpecialSkill {
			blasterAttack,
			equipmentAttack
		};

		typedef qint16(CloneSpecialSkill::* SkillFunction)();

		CloneSpecialSkill(qint16 blaster, qint16 equipment);
		~CloneSpecialSkill();

		qint16 blasterAttack();
		qint16 equipmentAttack();

		void setBlasterDamage(qint16 newBlasterDamage);
		void setEquipmentDamage(qint16 newMeleeDamage);

		// @note: getSkill map as function pointers
		QMap<SpecialSkill, SkillFunction> getSkills();

		// @note: this functions will be used after level up and new skill unlocked
		void addSkill(CloneSpecialSkill::SpecialSkill newSkillName, CloneSpecialSkill::SkillFunction newSkill);

	private:
		Damage mBlasterSpecialDamage;
		Damage mEquipmentSpecialDamage;

		QMap<SpecialSkill, SkillFunction> skillLut{
			{SpecialSkill::blasterAttack, &CloneSpecialSkill::blasterAttack},
			{SpecialSkill::equipmentAttack, &CloneSpecialSkill::equipmentAttack}
		};
	};

};
