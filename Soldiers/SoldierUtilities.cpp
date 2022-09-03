#include "SoldierUtilities.h"

typedef SoldierSpace::Damage Damage;
typedef SoldierSpace::AbstractWeapon AbstractWeapon;
typedef SoldierSpace::CloneWeapon CloneWeapon;
typedef SoldierSpace::DroidWeapon DroidWeapon;
typedef SoldierSpace::AbstractCommonSkill AbstractCommonSkill;
typedef SoldierSpace::CloneCommonSkill CloneCommonSkill;
typedef SoldierSpace::DroidCommonSkill DroidCommonSkill;
typedef SoldierSpace::CloneSpecialSkill CloneSpecialSkill;

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

AbstractWeapon::AbstractWeapon(Range range)
{
	setRange(range);
}

AbstractWeapon::~AbstractWeapon()
{
}

bool AbstractWeapon::isLongRange()
{
	return (mRange == Range::LONG) ? true : false;
}

void AbstractWeapon::setRange(Range range)
{
	mRange = range;
}

CloneWeapon::CloneWeapon(Weapon newWeapon, Range range)
	: AbstractWeapon(range)
{
	setWeapon(newWeapon);
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

qint16 CloneWeapon::getWeaponDamage()
{
	qint16 damage = mWeaponDamage.damage();

	return damage;
}

QString CloneWeapon::WeaponString()
{
	Weapon currentWeapon = static_cast<CloneWeapon::Weapon>(getWeapon());

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


/* AbstractCommonSkill Definitions */

AbstractCommonSkill::AbstractCommonSkill(qint16 level)
{
	mCurrentCharacterLevel = level;
}

AbstractCommonSkill::~AbstractCommonSkill()
{
}

void AbstractCommonSkill::setCurrentLevel(qint16 level)
{
	mCurrentCharacterLevel = level;
}

QVector<AbstractCommonSkill::CommonSkill> AbstractCommonSkill::getCurrentSkills()
{
	return mCurrentSkills;
}

void AbstractCommonSkill::addSkill(AbstractCommonSkill::CommonSkill newSkillName)
{
	mCurrentSkills.append(newSkillName);
}

QStringList SoldierSpace::AbstractCommonSkill::skillsString()
{
	qint16 skillNumber = mSkillName.size();

	QStringList skillList = QStringList();

	for (auto it = mSkillName.begin(); it != mSkillName.end(); it++) {

		QString skillString = it.value();

		skillList.append(skillString);
	}

	return skillList;
}

/* CloneCommonSkill Definitions */

CloneCommonSkill::CloneCommonSkill(CloneWeapon newWeapon, qint16 level)
	: AbstractCommonSkill(level)
{
	mWeapon = &newWeapon;

	updateSkillModifiers();
}

CloneCommonSkill::~CloneCommonSkill()
{
	delete mWeapon;
	
	mWeapon = nullptr;
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
			if (!mWeapon->isLongRange()) {
				it.value() = mCurrentCharacterLevel % 2;
			}
			else if (mWeapon->isLongRange()) {
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

	qint16 rawDamage = mWeapon->getWeaponDamage();

	qint16 finalDamage = rawDamage + damageModifier;

	return finalDamage;
}

void CloneCommonSkill::setWeapon(void* weapon)
{
	mWeapon = static_cast<CloneWeapon*>(weapon);
}

/* DroidCommonSkill Definitions */

DroidCommonSkill::DroidCommonSkill(DroidWeapon newWeapon, qint16 level)
	: AbstractCommonSkill(level)
{
	mWeapon = &newWeapon;

	updateSkillModifiers();
}

DroidCommonSkill::~DroidCommonSkill()
{
	delete mWeapon;

	mWeapon = nullptr;
}

void DroidCommonSkill::updateSkillModifiers()
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
			if (!mWeapon->isLongRange()) {
				it.value() = mCurrentCharacterLevel % 2;
			}
			else if (mWeapon->isLongRange()) {
				it.value() = mCurrentCharacterLevel % 4;
			}
			break;
		}
		default:
			break;
		}
	}
}

qint16 DroidCommonSkill::attack(CommonSkill skill)
{
	qint16 damage = 0;

	/* @note: take damage modifier */

	qint16 damageModifier = mSkillDamageLut[skill];

	/* @note: take weapon damage */

	qint16 rawDamage = mWeapon->getWeaponDamage();

	qint16 finalDamage = rawDamage + damageModifier;

	return finalDamage;
}

void DroidCommonSkill::setWeapon(void* weapon)
{
	mWeapon = static_cast<DroidWeapon*>(weapon);
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

