#include "CloneSoldier.h"

// @note: CloneAttack class will be implemented

Clone::Clone(qint16 health, qint16 armor, QString lifeForm, QString soldierType, CloneWeapon::Weapon weapon)
    : CloneAttack(weapon)
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
            CloneSpecialSkill::SpecialSkill specialSkillNumber = static_cast<CloneSpecialSkill::SpecialSkill>(attackNumber);
            returnDamage = CloneAttack::attack(specialSkillNumber);
            break;
        }

        default:
        {
            returnDamage = CloneAttack::attack(mCurrentWeapon);
            break;
        }
    }

    return returnDamage;
}
