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

QString CloneAttack::getWeaponStr()
{
    return mCurrentWeapon.getWeaponStr();
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

bool CloneAttack::addSkill(skillType skillType, qint16 skill)
{
    bool isAdded = true;

    switch (skillType)
    {
    case CloneAttack::commonSkill: {
        CloneCommonSkill::CommonSkill newSkill = static_cast<CloneCommonSkill::CommonSkill>(skill);
        mCurrentCommonSkills.addSkill(newSkill);
        break;
    }
    case CloneAttack::specialSkill: {
        CloneSpecialSkill::Equipment newSkill = static_cast<CloneSpecialSkill::Equipment>(skill);
        mCurrentSpecialSkills.addSkill(newSkill);
        break;
    }
    default:
        isAdded = false;
        break;
    }

    return isAdded;
}

