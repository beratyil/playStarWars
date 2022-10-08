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

	//TODO: COMBINE1 CloneWeapon Class and DroidWeapon Classes
	class AbstractWeapon
	{
	public:
		enum class Range {
			LONG,
			SHORT,
			UNINITIALIZED
		};

		AbstractWeapon() = default;
		AbstractWeapon(Range range);

		~AbstractWeapon();

		virtual QString getWeaponStr() = 0;

		virtual qint16 getWeaponDamage() = 0;

		bool isLongRange();

		Range getRange();

		void setRange(Range range);

		static qint16 getRangeIndex(Range range);
		static Range getRangeFromIndex(qint16 index);

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
			UNINITIALIZED
		};

		CloneWeapon() = default;
		CloneWeapon(Weapon newWeapon, Range range);

		~CloneWeapon();

		void setWeapon(Weapon newWeapon);
		Weapon getWeapon();

		QString getWeaponStr() override;
		qint16 getWeaponDamage() override;

		static qint16 getWeaponIndex(Weapon weapon);
		static Weapon getWeaponFromIndex(qint16 index);

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
			UNINITIALIZED
		};

		DroidWeapon() = default;
		DroidWeapon(Weapon newWeapon);

		~DroidWeapon();

		void setWeapon(Weapon newWeapon);
		Weapon getWeapon();

		QString getWeaponStr() override;
		qint16 getWeaponDamage() override;

		static qint16 getWeaponIndex(Weapon weapon);
		static Weapon getWeaponFromIndex(qint16 index);

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
			UNINITIALIZED
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
		virtual void updateSkillModifiers() = 0;

		virtual void setWeapon(void* weapon) = 0;

		void setCurrentLevel(qint16 level);

		QVector<CommonSkill> getCurrentSkills(); // @note: getSkill map as function pointers

		// @note: this functions will be used after level up and new skill unlocked
		void addSkill(AbstractCommonSkill::CommonSkill newSkillName);

		QStringList skillsString();

		static qint16 getCommonSkillIndex(CommonSkill skill);
		
		static CommonSkill getCommonSkillFromIndex(qint16 skill);

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
		* Update modifiers
		*/
		void updateSkillModifiers() override;

		void setWeapon(void* weapon) override;

	private:
		CloneWeapon* mWeapon;
		
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

		void updateSkillModifiers() override;

		void setWeapon(void* weapon) override;


	private:
		DroidWeapon* mWeapon;

	};

	class ISpecialSkill
	{
	public:
		friend class DroidSpecialSkill;
		friend class CloneSpecialSkill;

		ISpecialSkill() = default;

		virtual ~ISpecialSkill() {};

		/*
		Attack with selected equipment
		if no equipment, return -1
		*/
		virtual qint16 equipmentAttack(qint16 equipment) = 0;

		/*
		Update damage of selected equipment
		if selected equipment not exists return false, otherwise true
		*/
		virtual bool setEquipmentDamage(qint16 equipment, qint16 newDamage) = 0;

		// @note: this functions will be used after level up and new skill unlocked
		virtual void addSkill(qint16 newSkillName) = 0;

		virtual QStringList skillsString() = 0;

		//virtual qint16 getSpecialSkillIndex(CloneSpecialSkill skill) {};

	private:

	};

	class CloneSpecialSkill : public ISpecialSkill
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
			UNINITIALIZED
		};

		CloneSpecialSkill() = default;
		CloneSpecialSkill(Equipment equipment);
		
		~CloneSpecialSkill();

		/*
		Attack with selected equipment
		if no equipment, return -1
		*/
		qint16 equipmentAttack(qint16 equipment) override;
		
		qint16 equipmentAttack(Equipment equipment);

		/*
		Update damage of selected equipment
		if selected equipment not exists return false, otherwise true
		*/
		bool setEquipmentDamage(qint16 equipment, qint16 newDamage) override;

		// @note: getSkill map as function pointers
		QVector<Equipment> getCurrentSkills();

		// @note: this functions will be used after level up and new skill unlocked
		void addSkill(CloneSpecialSkill::Equipment newSkillName);
		
		void addSkill(qint16 newSkillName) override;

		QStringList skillsString() override;

		static qint16 getSpecialSkillIndex(CloneSpecialSkill::Equipment skill);

		static Equipment getSpecialSkillFromIndex(qint16 index);

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

	class DroidSpecialSkill : public ISpecialSkill
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
			WristRockect_Level1,
			WristRockect_Level2,
			WristRockect_Level3,
			RocketLauncher_Level1,
			RocketLauncher_Level2,
			RocketLauncher_Level3,
			UNINITIALIZED
		};

		DroidSpecialSkill() = default;
		DroidSpecialSkill(Equipment equipment);

		~DroidSpecialSkill();

		/*
		Attack with selected equipment
		if no equipment, return -1
		*/
		qint16 equipmentAttack(qint16 equipment) override;

		qint16 equipmentAttack(Equipment equipment);

		/*
		Update damage of selected equipment
		if selected equipment not exists return false, otherwise true
		*/
		bool setEquipmentDamage(qint16 equipment, qint16 newDamage) override;

		// @note: getSkill map as function pointers
		QVector<Equipment> getCurrentSkills();

		// @note: this functions will be used after level up and new skill unlocked
		void addSkill(DroidSpecialSkill::Equipment newSkillName);

		void addSkill(qint16 newSkillName) override;

		QStringList skillsString() override;

		static qint16 getSpecialSkillIndex(DroidSpecialSkill::Equipment skill);
		
		static Equipment getSpecialSkillFromIndex(qint16 index);

	private:
		
		QVector<Equipment> mCurrentSkills;

		QMap<Equipment, qint16> mSkillDamageLut = {
			{Equipment::HandGrenade_Level1, 5},
			{Equipment::HandGrenade_Level2, 10},
			{Equipment::HandGrenade_Level3, 20},
			{Equipment::MiniBlasterGun_Level1, 6},
			{Equipment::MiniBlasterGun_Level2, 12},
			{Equipment::MiniBlasterGun_Level3, 24},
			{Equipment::WristRockect_Level1, 7},
			{Equipment::WristRockect_Level2, 14},
			{Equipment::WristRockect_Level3, 28},
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
			{Equipment::WristRockect_Level1, "Grenade Launcher Level 1"},
			{Equipment::WristRockect_Level2, "Grenade Launcher Level 2"},
			{Equipment::WristRockect_Level3, "Grenade Launcher Level 3"},
			{Equipment::RocketLauncher_Level1, "Rocket Launcher Level 1"},
			{Equipment::RocketLauncher_Level2, "Rocket Launcher Level 2"},
			{Equipment::RocketLauncher_Level3, "Rocket Launcher Level 3"}
		};

	};

};
