#include "DroidSoldier.h"

// @note: DroidAttack class will be implemented

Droid::Droid(qint16 health, qint16 armor, QString lifeForm, SoldierType soldierType, DroidWeapon::Weapon weapon, DroidWeapon::Range range)
    : DroidAttack(weapon, range)
{
    setType(Type::Droid);

    setHealth(health);
    setArmor(armor);
    setLifeForm(lifeForm);
    setSoldierType(soldierType);
}

Droid::~Droid()
{
}

qint16 Droid::attack(qint16 abilityType, qint16 attackNumber)
{
    qint16 returnDamage = 0;

    switch (abilityType) {
    case skillType::commonSkill:
    {
        DroidCommonSkill::CommonSkill commonSkillNumber = static_cast<DroidCommonSkill::CommonSkill>(attackNumber);
        returnDamage = DroidAttack::attack(commonSkillNumber);
        break;
    }

    case skillType::specialSkill:
    {
        DroidSpecialSkill::Equipment specialSkillNumber = static_cast<DroidSpecialSkill::Equipment>(attackNumber);
        returnDamage = DroidAttack::attack(specialSkillNumber);
        break;
    }

    default:
    {
        break;
    }
    }

    return returnDamage;
}
