#include "SoldierUtilities.h"

typedef SoldierSpace::Damage Damage;
typedef SoldierSpace::CloneCommonSkill CloneCommonSkill;
typedef SoldierSpace::CloneSpecialSkill CloneSpecialSkill;
typedef SoldierSpace::CloneWeapon CloneWeapon;
typedef SoldierSpace::DroidWeapon DroidWeapon;

/* Damage Definitions */
Damage::Damage()
{
	mCurrentDamage = 0;
}

Damage::Damage(qint16 initDamage)
{
	setDamage(initDamage);
}

qint16 Damage::operator = (qint16 initDamage)
{
	setDamage(initDamage);
	return mCurrentDamage;
}

void Damage::setDamage(qint16 newDamage)
{
	mCurrentDamage = newDamage;
}

qint16 Damage::damage()
{
	return mCurrentDamage;
}

/* CloneWeapon Definitions */

CloneWeapon::CloneWeapon(Weapon newWeapon, Range range)
{
	setWeapon(newWeapon);

	setRange(range);
}

CloneWeapon::~CloneWeapon()
{
}

void CloneWeapon::setWeapon(Weapon newWeapon)
{
	mWeapon = newWeapon;

	auto it = mWeaponDamageLut.find(mWeapon);

	qint16 damage = it.value();
	
	mWeaponDamage.setDamage(damage);
}

CloneWeapon::Weapon CloneWeapon::getWeapon()
{
	return mWeapon;
}

QString CloneWeapon::WeaponString()
{
	Weapon currentWeapon = getWeapon();

	QString weaponString = "";

	switch (currentWeapon)
	{
	case Weapon::DC_15A_CARBINE:
		weaponString = "DC-15A BLASTER CARBINE";
		break;
	case Weapon::DC_15A_RIFLE:
		weaponString = "DC-15A BLASTER RIFLE";
		break;
	case Weapon::Z_6_ROTARY_CANON:
		weaponString = "Z6 ROTARY BLASTER CANON";
		break;
	case Weapon::DC_15X_SNIPER:
		weaponString = "DC-15x SNIPER BLASTER";
		break;
	default:
		break;
	}

	return weaponString;
}

qint16 CloneWeapon::getWeaponDamage()
{
	qint16 damage = mWeaponDamage.damage();

	return damage;
}

bool CloneWeapon::isLongRange()
{
	return (mRange == Range::LONG) ? true : false;
}

void CloneWeapon::setRange(Range range)
{
	mRange = range;
}


/* CloneCommonSkill Definitions */

CloneCommonSkill::CloneCommonSkill(CloneWeapon newWeapon, qint16 level)
{
	mWeapon = newWeapon;
	mCurrentCharacterLevel = level;

	updateSkillModifiers();
}

CloneCommonSkill::~CloneCommonSkill()
{
}

void CloneCommonSkill::setWeapon(CloneWeapon newWeapon)
{
	mWeapon = newWeapon;
}

void CloneCommonSkill::setCurrentLevel(qint16 level)
{
	mCurrentCharacterLevel = level;
}

void CloneCommonSkill::updateSkillModifiers()
{
	for (auto it = mSkillDamageLut.begin(); it != mSkillDamageLut.end(); it++)
	{
		switch (it.key()) {
			case CommonSkill::WeaponStrike:
			{
				it.value() = mCurrentCharacterLevel % 4;
				break;
			}
			case CommonSkill::HeadShot:
			{
				it.value() = mCurrentCharacterLevel % 2;
				break;
			}
			case CommonSkill::FasterReload:
			{
				break;
			}
			case CommonSkill::StrongSwing:
			{
				if (!mWeapon.isLongRange()) {
					it.value() = mCurrentCharacterLevel % 2;
				}
				else if (mWeapon.isLongRange()) {
					it.value() = mCurrentCharacterLevel % 4;
				}
				break;
			}
			default:
				break;
		}
	}
}

qint16 CloneCommonSkill::attack(CommonSkill skill)
{
	qint16 damage = 0;

	/* @note: take damage modifier */

	qint16 damageModifier = mSkillDamageLut[skill];

	/* @note: take weapon damage */

	qint16 rawDamage = mWeapon.getWeaponDamage();

	qint16 finalDamage = rawDamage + damageModifier;

	return finalDamage;
}


QVector<CloneCommonSkill::CommonSkill> CloneCommonSkill::getCurrentSkills()
{
	return mCurrentSkills;
}

void CloneCommonSkill::addSkill(CloneCommonSkill::CommonSkill newSkillName)
{
	mCurrentSkills.append(newSkillName);
}

QStringList SoldierSpace::CloneCommonSkill::skillsString()
{
	qint16 skillNumber = mSkillName.size();

	QStringList skillList = QStringList();

	for (auto it = mSkillName.begin(); it != mSkillName.end(); it++) {

		QString skillString = it.value();

		skillList.append(skillString);
	}

	return skillList;
}

/* CloneSpecialSkill Definitions */

CloneSpecialSkill::CloneSpecialSkill(Equipment equipment)
{
	mCurrentSkills.append(equipment);
}

CloneSpecialSkill::~CloneSpecialSkill()
{
}

QVector<CloneSpecialSkill::Equipment> CloneSpecialSkill::getCurrentSkills()
{
	return mCurrentSkills;
}

void CloneSpecialSkill::addSkill(CloneSpecialSkill::Equipment newSkillName)
{
	mCurrentSkills.append(newSkillName);
}

QStringList SoldierSpace::CloneSpecialSkill::skillsString()
{
	qint16 skillNumber = mSkillName.size();

	QStringList skillList = QStringList();

	for (auto it = mSkillName.begin(); it != mSkillName.end(); it++) {
		
		QString skillString = it.value();

		skillList.append(skillString);
	}

	return skillList;
}

qint16 CloneSpecialSkill::equipmentAttack(Equipment equipment)
{
	qint16 damage = 0;

	/* @note: take damage directly from Skill Damage Look Up Table */

	damage = mSkillDamageLut[equipment];

	/* @note: take weapon damage */

	return damage;
}

/* DroidWeapon Definitions */

SoldierSpace::DroidWeapon::DroidWeapon(Weapon newWeapon)
{
	mWeapon = newWeapon;
}

DroidWeapon::~DroidWeapon()
{
}

void DroidWeapon::setWeapon(Weapon newWeapon)
{
	mWeapon = newWeapon;

	auto it = mWeaponDamageLut.find(mWeapon);

	qint16 damage = it.value();

	mWeaponDamage.setDamage(damage);
}

DroidWeapon::Weapon DroidWeapon::getWeapon()
{
	return mWeapon;
}

QString DroidWeapon::WeaponString()
{
	Weapon currentWeapon = getWeapon();

	QString weaponString = "";

	switch (currentWeapon)
	{
	case Weapon::E_5_BLASTER_RIFLE:
		weaponString = "E 5 BLASTER RIFLE";
		break;
	case Weapon::DUAL_WRIST_BLASTER:
		weaponString = "DUAL WRIST BLASTER";
		break;
	case Weapon::BLASTER_CANNON:
		weaponString = "BLASTER CANNON";
		break;
	case Weapon::RADIATION_CANNON:
		weaponString = "RADIATION CANNON";
		break;
	case Weapon::VIBROSTAFF:
		weaponString = "VIBRO STAFF";
		break;
	case Weapon::ELECTROSTAFF:
		weaponString = "ELECTROSTAFF";
		break;
	default:
		break;
	}
	return weaponString;
}

qint16 DroidWeapon::getWeaponDamage()
{
	qint16 damage = mWeaponDamage.damage();

	return damage;
}

