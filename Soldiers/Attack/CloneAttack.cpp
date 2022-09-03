#include "CloneAttack.h"

CloneAttack::CloneAttack(CloneWeapon::Weapon newWeapon, CloneWeapon::Range range)
{
    mCurrentWeapon.setWeapon(newWeapon);
    mCurrentWeapon.setRange(range);
}


CloneAttack::CloneAttack(CloneWeapon newWeapon)
{
    mCurrentWeapon = newWeapon;
}

CloneAttack::~CloneAttack()
{
}

qint16 CloneAttack::attack(CloneWeapon weapon)
{
    return mCurrentWeapon.getWeaponDamage();
}

qint16 CloneAttack::attack(CloneCommonSkill::CommonSkill commonSkill)
{
    quint16 returnDamage = 0;

    returnDamage = mCurrentCommonSkills.attack(commonSkill);

    return returnDamage;
}

qint16 CloneAttack::attack(CloneSpecialSkill::Equipment specialSkill)
{
    quint16 returnDamage = 0;
    
    returnDamage = mCurrentSpecialSkills.equipmentAttack(specialSkill);
    
    return returnDamage;
}

CloneWeapon CloneAttack::getWeapon()
{
    return mCurrentWeapon;
}

QVector<CloneCommonSkill::CommonSkill> CloneAttack::getCommonSkills()
{
    return mCurrentCommonSkills.getCurrentSkills();
}

QVector<CloneSpecialSkill::Equipment> CloneAttack::getSpecialSkills()
{
    return mCurrentSpecialSkills.getCurrentSkills();
}

QStringList CloneAttack::getCommonSkillsString()
{
    return mCurrentCommonSkills.skillsString();
}

QStringList CloneAttack::getSpecialSkillsString()
{
    return mCurrentSpecialSkills.skillsString();
}

void CloneAttack::updateWeapon(CloneWeapon newWeapon)
{
    mCurrentWeapon = newWeapon;
}