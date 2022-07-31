#include "Utilities.h"

typedef SoldierSpace::Damage Damage;
typedef SoldierSpace::CloneCommonSkill CloneCommonSkill;
typedef SoldierSpace::CloneSpecialSkill CloneSpecialSkill;
typedef SoldierSpace::CloneWeapon CloneWeapon;
typedef CloneWeapon::Weapon Weapon;

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

CloneWeapon::CloneWeapon(Weapon newWeapon)
{
	weapon = newWeapon;
}

CloneWeapon::~CloneWeapon()
{
}

void CloneWeapon::setWeapon(Weapon newWeapon)
{
	weapon = newWeapon;

	qint16 damage = WeaponDamageMap.take(weapon);
	
	weaponDamage.setDamage(damage);
}

Weapon CloneWeapon::getWeapon()
{
	return weapon;
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
	qint16 damage = weaponDamage.damage();

	return damage;
}

/* CloneCommonSkill Definitions */

CloneCommonSkill::CloneCommonSkill(qint16 closeRange, qint16 longRange)
{
	mCloseRangeDamage = closeRange;
	mLongRangeDamage = longRange;
}

CloneCommonSkill::~CloneCommonSkill()
{
}

void CloneCommonSkill::setMeleeDamage(qint16 newMeleeDamage)
{
	mCloseRangeDamage.setDamage(newMeleeDamage);
}

void CloneCommonSkill::setBlasterDamage(qint16 newBlasterDamage)
{
	mLongRangeDamage.setDamage(newBlasterDamage);
}

qint16 CloneCommonSkill::blasterAttack()
{
	return mLongRangeDamage.damage();
}

qint16 CloneCommonSkill::meleeAttack()
{
	return mCloseRangeDamage.damage();
}

QMap<CloneCommonSkill::CommonSkill, CloneCommonSkill::SkillFunction> CloneCommonSkill::getSkills()
{
	return skillLut;
}

void CloneCommonSkill::addSkill(CloneCommonSkill::CommonSkill newSkillName, SkillFunction newSkill)
{
	skillLut.insert(newSkillName, newSkill);
}

QStringList SoldierSpace::CloneCommonSkill::skillsString()
{
	qint16 skillNumber = skillLut.size();
	
	QStringList skillList = QStringList();

	for (auto it = skillLut.begin(); it != skillLut.end(); it++) {
		auto skill = it.key();

		QString skillString = convertString(skill);

		skillList.append(skillString);
	}

	return skillList;
}

QString SoldierSpace::CloneCommonSkill::convertString(CommonSkill skill)
{
	QString stringSkill = "";

	if (skill == CommonSkill::blasterAttack) {
		stringSkill = "Blaster Attack";
	}
	else if (skill == CommonSkill::meleeAttack) {
		stringSkill = "Melee Attack";
	}

	return stringSkill;
}

/* CloneSpecialSkill Definitions */

CloneSpecialSkill::CloneSpecialSkill(qint16 blaster, qint16 equipment)
{
	mBlasterSpecialDamage = blaster;
	mEquipmentSpecialDamage = equipment;
}

CloneSpecialSkill::~CloneSpecialSkill()
{
}

void CloneSpecialSkill::setEquipmentDamage(qint16 newMeleeDamage)
{
	mEquipmentSpecialDamage.setDamage(newMeleeDamage);
}

void CloneSpecialSkill::setBlasterDamage(qint16 newBlasterDamage)
{
	mBlasterSpecialDamage.setDamage(newBlasterDamage);
}

qint16 CloneSpecialSkill::blasterAttack()
{
	return mBlasterSpecialDamage.damage();
}

qint16 CloneSpecialSkill::equipmentAttack()
{
	return mEquipmentSpecialDamage.damage();
}

QMap<CloneSpecialSkill::SpecialSkill, CloneSpecialSkill::SkillFunction> CloneSpecialSkill::getSkills()
{
	return skillLut;
}

void CloneSpecialSkill::addSkill(CloneSpecialSkill::SpecialSkill newSkillName, CloneSpecialSkill::SkillFunction newSkill)
{
	skillLut.insert(newSkillName, newSkill);
}

QStringList SoldierSpace::CloneSpecialSkill::skillsString()
{
	qint16 skillNumber = skillLut.size();

	QStringList skillList = QStringList();

	for (auto it = skillLut.begin(); it != skillLut.end(); it++) {
		auto skill = it.key();

		QString skillString = convertString(skill);

		skillList.append(skillString);
	}

	return skillList;
}

QString SoldierSpace::CloneSpecialSkill::convertString(SpecialSkill skill)
{
	QString stringSkill = "";

	if (skill == SpecialSkill::blasterAttack) {
		stringSkill = "Blaster Attack";
	}
	else if (skill == SpecialSkill::equipmentAttack) {
		stringSkill = "Equipment Attack";
	}

	return stringSkill;
}
