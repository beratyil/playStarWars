#include "DroidSoldier.h"

// @note: DroidAttack class will be implemented

Droid::Droid(QString charName, QString lifeForm, SoldierType soldierType, qint16 level, DroidWeapon::Weapon weapon, DroidWeapon::Range range)
    : Soldier(charName, level)
    , DroidAttack(weapon, range)
    , Health(level, soldierType)
{
    setType(Type::Droid);

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
