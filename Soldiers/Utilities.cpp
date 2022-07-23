#include "Utilities.h"

typedef SoldierSpace::Damage Damage;
typedef SoldierSpace::CloneCommonSkill CloneCommonSkill;
typedef SoldierSpace::CloneSpecialSkill CloneSpecialSkill;
typedef SoldierSpace::CloneWeapon CloneWeapon;
typedef CloneWeapon::Weapon Weapon;
typedef SoldierSpace::CloneCommonSkill::SkillFunction SkillFunction;

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
	case DC_15A_CARBINE:
		weaponString = "DC-15A BLASTER CARBINE";
		break;
	case DC_15A_RIFLE:
		weaponString = "DC-15A BLASTER RIFLE";
		break;
	case Z_6_ROTARY_CANON:
		weaponString = "Z6 ROTARY BLASTER CANON";
		break;
	case DC_15X_SNIPER:
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

	/* @note: For adding elements to skillMap, both this line, and the statement in the header works, but I prefer
	statement on the header because it is a look up table */

	/*skillMap.insert(BLASTERATTACK, &CloneCommonSkill::blasterAttack);
	skillMap.insert(MELEEATTACK, &CloneCommonSkill::meleeAttack);*/
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

QMap<CloneCommonSkill::CommonSkill, SkillFunction> CloneCommonSkill::getSkills()
{
	return skillMap;
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