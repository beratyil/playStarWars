// @Explaining: This class for every Clone Attack
// Simple Attack
//      hand to hand combat
//      blaster attack
// Special Attack
//      handgranade
//      headshot

#pragma once

#include "..\\SoldierUtilities.h"

using SoldierSpace::CloneCommonSkill;
using SoldierSpace::CloneSpecialSkill;
using SoldierSpace::CloneWeapon;

//CloneAttack Class
//Wrapps every attack operation
//Common Skills, Special Skills or Normal Attack
class CloneAttack
{

public:

    typedef enum skillType{
        commonSkill,
        specialSkill
    };

    CloneAttack() = default;

    CloneAttack(CloneWeapon newWeapon);
    ~CloneAttack();

    void updateGun(CloneWeapon newWeapon);

    CloneWeapon getWeapon();

    QMap<CloneCommonSkill::CommonSkill, CloneCommonSkill::SkillFunction> getCommonSkills();

    QMap<CloneSpecialSkill::SpecialSkill, CloneSpecialSkill::SkillFunction> getSpecialSkills();

    QStringList getCommonSkillsString();

    QStringList getSpecialSkillsString();

protected:
    qint16 attack(CloneWeapon weapon);

    qint16 attack(CloneCommonSkill::CommonSkill commonSkill);

    qint16 attack(CloneSpecialSkill::SpecialSkill specialSkill);

    CloneWeapon mCurrentWeapon;
    CloneCommonSkill mCurrentCommonSkills;
    CloneSpecialSkill mCurrentSpecialSkills;

    
};
