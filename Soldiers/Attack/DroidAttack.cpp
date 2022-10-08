#include "DroidAttack.h"

DroidAttack::DroidAttack(DroidWeapon::Weapon newWeapon, DroidWeapon::Range range)
{
    mCurrentWeapon.setWeapon(newWeapon);
    mCurrentWeapon.setRange(range);
}


DroidAttack::DroidAttack(DroidWeapon newWeapon)
{
    mCurrentWeapon = newWeapon;
}

DroidAttack::~DroidAttack()
{
}

qint16 DroidAttack::attack(DroidCommonSkill::CommonSkill commonSkill)
{
    quint16 returnDamage = 0;

    returnDamage = mCurrentCommonSkills.attack(commonSkill);

    return returnDamage;
}

qint16 DroidAttack::attack(DroidSpecialSkill::Equipment specialSkill)
{
    quint16 returnDamage = 0;

    returnDamage = mCurrentSpecialSkills.equipmentAttack(specialSkill);

    return returnDamage;
}

DroidWeapon DroidAttack::getWeapon()
{
    return mCurrentWeapon;
}

QString DroidAttack::getWeaponStr()
{
    return mCurrentWeapon.getWeaponStr();
}

QVector<DroidCommonSkill::CommonSkill> DroidAttack::getCommonSkills()
{
    return mCurrentCommonSkills.getCurrentSkills();
}

QVector<DroidSpecialSkill::Equipment> DroidAttack::getSpecialSkills()
{
    return mCurrentSpecialSkills.getCurrentSkills();
}

QStringList DroidAttack::getCommonSkillsString()
{
    return mCurrentCommonSkills.skillsString();
}

QStringList DroidAttack::getSpecialSkillsString()
{
    return mCurrentSpecialSkills.skillsString();
}

void DroidAttack::updateWeapon(DroidWeapon newWeapon)
{
    mCurrentWeapon = newWeapon;
}

bool DroidAttack::addSkill(skillType skillType, qint16 skill)
{
    bool isAdded = true;

    switch (skillType)
    {
    case DroidAttack::commonSkill: {
        DroidCommonSkill::CommonSkill newSkill = static_cast<DroidCommonSkill::CommonSkill>(skill);
        mCurrentCommonSkills.addSkill(newSkill);
        break;
    }
    case DroidAttack::specialSkill: {
        DroidSpecialSkill::Equipment newSkill = static_cast<DroidSpecialSkill::Equipment>(skill);
        mCurrentSpecialSkills.addSkill(newSkill);
        break;
    }
    default:
        isAdded = false;
        break;
    }

    return isAdded;
}

DroidWeapon::Range DroidAttack::getWeaponRange()
{
    bool isLong = mCurrentWeapon.isLongRange();

    return (isLong == true) ? DroidWeapon::Range::LONG : DroidWeapon::Range::SHORT;
}
