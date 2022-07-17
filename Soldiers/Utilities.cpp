#include "Utilities.h"

typedef SoldierSpace::Damage Damage;
typedef SoldierSpace::CloneCommonSkill CloneCommonSkill;
typedef SoldierSpace::CloneSpecialSkill CloneSpecialSkill;

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