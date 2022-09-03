#include "CloneAttack.h"

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

    QMap<CloneCommonSkill::CommonSkill, CloneCommonSkill::SkillFunction> skills = mCurrentCommonSkills.getSkills();
    auto skill = skills.find(commonSkill);

    CloneCommonSkill::SkillFunction function = skill.value();

    //returnDamage = function();

    return returnDamage;
}

qint16 CloneAttack::attack(CloneSpecialSkill::SpecialSkill specialSkill)
{
    quint16 returnDamage = 0;

    QMap<CloneSpecialSkill::SpecialSkill, CloneSpecialSkill::SkillFunction> skills = mCurrentSpecialSkills.getSkills();
    auto skill = skills.find(specialSkill);
    
    CloneSpecialSkill::SkillFunction function = skill.value();
    
    //returnDamage = function();
    
    return returnDamage;
}

CloneWeapon CloneAttack::getWeapon()
{
    return mCurrentWeapon;
}

QMap<CloneCommonSkill::CommonSkill, CloneCommonSkill::SkillFunction> CloneAttack::getCommonSkills()
{
    return mCurrentCommonSkills.getSkills();
}

QMap<CloneSpecialSkill::SpecialSkill, CloneSpecialSkill::SkillFunction> CloneAttack::getSpecialSkills()
{
    return mCurrentSpecialSkills.getSkills();
}

QStringList CloneAttack::getCommonSkillsString()
{
    return mCurrentCommonSkills.skillsString();
}

QStringList CloneAttack::getSpecialSkillsString()
{
    return mCurrentSpecialSkills.skillsString();
}

void CloneAttack::updateGun(CloneWeapon newWeapon)
{
    mCurrentWeapon = newWeapon;
}