#include "CloneAttack.h"

CloneAttack::CloneAttack(CloneWeapon newWeapon)
{
    currentWeapon = newWeapon;
}

CloneAttack::~CloneAttack()
{
}

qint16 CloneAttack::attack(CloneWeapon weapon)
{
    return currentWeapon.getWeaponDamage();
}

qint16 CloneAttack::attack(CloneCommonSkill::CommonSkill commonSkill)
{
    quint16 returnDamage = 0;

    QMap<CloneCommonSkill::CommonSkill, CloneCommonSkill::SkillFunction> skills = currentCommonSkills.getSkills();
    auto skill = skills.find(commonSkill);

    CloneCommonSkill::SkillFunction function = skill.value();

    //returnDamage = function();

    return returnDamage;
}

qint16 CloneAttack::attack(CloneSpecialSkill::SpecialSkill specialSkill)
{
    quint16 returnDamage = 0;

    QMap<CloneSpecialSkill::SpecialSkill, CloneSpecialSkill::SkillFunction> skills = currentSpecialSkills.getSkills();
    auto skill = skills.find(specialSkill);
    
    CloneSpecialSkill::SkillFunction function = skill.value();
    
    //returnDamage = function();
    
    return returnDamage;
}

CloneWeapon CloneAttack::getWeapon()
{
    return currentWeapon;
}

void CloneAttack::updateGun(CloneWeapon newWeapon)
{
    currentWeapon = newWeapon;
}