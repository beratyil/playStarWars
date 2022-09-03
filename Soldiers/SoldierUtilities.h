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

	class AbstractWeapon
	{
	public:

		enum class Range {
			LONG,
			SHORT
		};

		AbstractWeapon() = default;
		AbstractWeapon(Range range);

		~AbstractWeapon();


		virtual QString WeaponString() = 0;

		virtual qint16 getWeaponDamage() = 0;

		bool isLongRange();

		void setRange(Range range);

	protected:
		Range mRange;
		Damage mWeaponDamage;

	};

	class CloneWeapon : public AbstractWeapon
	{
	public:

		enum class Weapon {
			DC_15A_CARBINE,
			DC_15A_RIFLE,
			Z_6_ROTARY_CANON,
			DC_15X_SNIPER,
			DC_17M_BLASTER,
		};

		CloneWeapon() = default;
		CloneWeapon(Weapon newWeapon, Range range);

		~CloneWeapon();

		void setWeapon(Weapon newWeapon);
		Weapon getWeapon();

		QString WeaponString() override;
		qint16 getWeaponDamage() override;

	private:
		Weapon mWeapon;
		QMap<Weapon, qint16> mWeaponDamageLut{
			{Weapon::DC_15A_CARBINE, 2},
			{Weapon::DC_15A_RIFLE, 3},
			{Weapon::Z_6_ROTARY_CANON, 5},
			{Weapon::DC_15X_SNIPER, 4} 
		};

	};

	class DroidWeapon : public AbstractWeapon
	{
	public:

		enum class Weapon {
			E_5_BLASTER_RIFLE,
			DUAL_WRIST_BLASTER,
			BLASTER_CANNON,
			RADIATION_CANNON,
			VIBROSTAFF,
			ELECTROSTAFF,
		};

		DroidWeapon() = default;
		DroidWeapon(Weapon newWeapon);

		~DroidWeapon();

		void setWeapon(Weapon newWeapon);
		Weapon getWeapon();

		QString WeaponString() override;
		qint16 getWeaponDamage() override;

	private:
		Weapon mWeapon;

		QMap<Weapon, qint16> mWeaponDamageLut{
			{Weapon::E_5_BLASTER_RIFLE, 2},
			{Weapon::DUAL_WRIST_BLASTER, 3},
			{Weapon::BLASTER_CANNON, 3},
			{Weapon::RADIATION_CANNON, 4},
			{Weapon::VIBROSTAFF, 6},
			{Weapon::ELECTROSTAFF, 7},
		};

	};

	class AbstractCommonSkill
	{

	public:

		enum class CommonSkill {
			WeaponStrike,
			HeadShot,
			FasterReload, //LesserReloadTime,
			StrongSwing, //Melee weapon
		};

		AbstractCommonSkill() = default;
		AbstractCommonSkill(qint16 newLevel);

		~AbstractCommonSkill();

		/*
		Attack with selected skill
		*/
		virtual qint16 attack(CommonSkill skill) = 0;

		/*
		* Update modifiers
		*/
		void updateSkillModifiers();

		virtual void setWeapon(void* weapon) = 0;

		void setCurrentLevel(qint16 level);

		QVector<CommonSkill> getCurrentSkills(); // @note: getSkill map as function pointers

		// @note: this functions will be used after level up and new skill unlocked
		void addSkill(AbstractCommonSkill::CommonSkill newSkillName);

		QStringList skillsString();

	protected:
		qint16 mCurrentCharacterLevel;

		QMap<CommonSkill, qint16> mSkillDamageLut = {
			{CommonSkill::WeaponStrike, 0},
			{CommonSkill::HeadShot, 2},
			{CommonSkill::FasterReload, 0},
			{CommonSkill::StrongSwing, 1},
		};

		QMap<CommonSkill, QString> mSkillName = {
			{CommonSkill::WeaponStrike, "Attack"},
			{CommonSkill::HeadShot, "Head Shot"},
			{CommonSkill::FasterReload, "Faster Reload"},
			{CommonSkill::StrongSwing, "Stronger Swing"},
		};

		QVector<CommonSkill> mCurrentSkills;
	};

	class CloneCommonSkill : public AbstractCommonSkill
	{

	public:

		CloneCommonSkill() = default;
		CloneCommonSkill(CloneWeapon newWeapon, qint16 newLevel);

		~CloneCommonSkill();

		/*
		Attack with selected skill
		*/
		qint16 attack(CommonSkill skill) override;

		/*
		Attack with selected skill
		*/
		//qint16 closeRangeAttack(CommonSkill skill);

		/*
		* Update modifiers
		*/
		void updateSkillModifiers();

		void setWeapon(void* weapon) override;

	private:
		CloneWeapon* mWeapon;
		
	};


	class CloneSpecialSkill
	{
	public:
		
		/*
		* @note: Four Different Type of Equipment
		* 1)Hand Grenade
		* 2)MiniGun like blaster
		* 3)Granade Launcher
		* 4)Rocket Launcher
		* Every equipment has three levels. Each level will have specific identifier
		*/
		enum class Equipment {
			HandGrenade_Level1,
			HandGrenade_Level2,
			HandGrenade_Level3,
			MiniBlasterGun_Level1,
			MiniBlasterGun_Level2,
			MiniBlasterGun_Level3,
			GrenadeLauncher_Level1,
			GrenadeLauncher_Level2,
			GrenadeLauncher_Level3,
			RocketLauncher_Level1,
			RocketLauncher_Level2,
			RocketLauncher_Level3,
		};

		typedef qint16(CloneSpecialSkill::* SkillFunction)();

		CloneSpecialSkill() = default;
		CloneSpecialSkill(Equipment equipment);
		
		~CloneSpecialSkill();

		/*
		Attack with selected equipment
		if no equipment, return -1
		*/
		qint16 equipmentAttack(Equipment equipment);

		/*
		Update damage of selected equipment
		if selected equipment not exists return false, otherwise true
		*/
		bool setEquipmentDamage(Equipment equipment, qint16 newDamage);

		// @note: getSkill map as function pointers
		QVector<Equipment> getCurrentSkills();

		// @note: this functions will be used after level up and new skill unlocked
		void addSkill(CloneSpecialSkill::Equipment newSkillName);

		QStringList skillsString();


	private:
		QVector<Equipment> mCurrentSkills;
		
		QMap<Equipment, qint16> mSkillDamageLut = {
			{Equipment::HandGrenade_Level1, 5},
			{Equipment::HandGrenade_Level2, 10},
			{Equipment::HandGrenade_Level3, 20},
			{Equipment::MiniBlasterGun_Level1, 6},
			{Equipment::MiniBlasterGun_Level2, 12},
			{Equipment::MiniBlasterGun_Level3, 24},
			{Equipment::GrenadeLauncher_Level1, 7},
			{Equipment::GrenadeLauncher_Level2, 14},
			{Equipment::GrenadeLauncher_Level3, 28},
			{Equipment::RocketLauncher_Level1, 10},
			{Equipment::RocketLauncher_Level2, 20},
			{Equipment::RocketLauncher_Level3, 40},
		};

		QMap<Equipment, QString> mSkillName{
			{Equipment::HandGrenade_Level1, "Hand Grenade Level 1"},
			{Equipment::HandGrenade_Level2, "Hand Grenade Level 2"},
			{Equipment::HandGrenade_Level3, "Hand Grenade Level 3"},
			{Equipment::MiniBlasterGun_Level1, "Mini Blaster Gun Level 1"},
			{Equipment::MiniBlasterGun_Level2, "Mini Blaster Gun Level 2"},
			{Equipment::MiniBlasterGun_Level3, "Mini Blaster Gun Level 3"},
			{Equipment::GrenadeLauncher_Level1, "Grenade Launcher Level 1"},
			{Equipment::GrenadeLauncher_Level2, "Grenade Launcher Level 2"},
			{Equipment::GrenadeLauncher_Level3, "Grenade Launcher Level 3"},
			{Equipment::RocketLauncher_Level1, "Rocket Launcher Level 1"},
			{Equipment::RocketLauncher_Level2, "Rocket Launcher Level 2"},
			{Equipment::RocketLauncher_Level3, "Rocket Launcher Level 3"}
		};

	};

	class DroidCommonSkill : public AbstractCommonSkill
	{

	public:
		typedef qint16(CloneCommonSkill::* SkillFunction)();

		DroidCommonSkill() = default;
		DroidCommonSkill(DroidWeapon newWeapon, qint16 newLevel);

		~DroidCommonSkill();

		/*
		Attack with selected skill
		*/
		qint16 attack(CommonSkill skill) override;

		void updateSkillModifiers();

		void setWeapon(void* weapon) override;


	private:
		DroidWeapon* mWeapon;
		
	};


};
