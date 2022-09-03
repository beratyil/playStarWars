#include "CloneSoldier.h"

// @note: CloneAttack class will be implemented

Clone::Clone(qint16 health, qint16 armor, QString lifeForm, QString soldierType, CloneWeapon::Weapon weapon, CloneWeapon::Range range)
    : CloneAttack(weapon, range)
{
    setHealth(health);
    setArmor(armor);
    setLifeForm(lifeForm);
    setSoldierType(soldierType);
}

Clone::~Clone()
{
}

qint16 Clone::attack(qint16 abilityType, qint16 attackNumber)
{
    qint16 returnDamage = 0;

    switch (abilityType){
        case skillType::commonSkill:
        {
            CloneCommonSkill::CommonSkill commonSkillNumber = static_cast<CloneCommonSkill::CommonSkill>(attackNumber);
            returnDamage = CloneAttack::attack(commonSkillNumber);
            break;
        }

        case skillType::specialSkill:
        {
            CloneSpecialSkill::Equipment specialSkillNumber = static_cast<CloneSpecialSkill::Equipment>(attackNumber);
            returnDamage = CloneAttack::attack(specialSkillNumber);
            break;
        }

        default:
        {
            break;
        }
    }

    return returnDamage;
}
