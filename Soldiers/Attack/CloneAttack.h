// @Explaining: This class for every Clone Attack
// Simple Attack
//      hand to hand combat
//      blaster attack
// Special Attack
//      handgranade
//      headshot


#pragma once

#include "..\\Utilities.h"

using SoldierSpace::CloneCommonSkill;
using SoldierSpace::CloneSpecialSkill;
using SoldierSpace::CloneWeapon;

class CloneAttack
{

public:
    CloneAttack() = default;

    CloneAttack(CloneWeapon newWeapon);
    ~CloneAttack();

    qint16 attack(CloneWeapon weapon);
    
    qint16 attack(CloneCommonSkill::CommonSkill commonSkill);
    
    qint16 attack(CloneSpecialSkill::SpecialSkill specialSkill);

    void updateGun(CloneWeapon newWeapon);

    CloneWeapon getWeapon();

private:
    CloneWeapon currentWeapon;
    CloneCommonSkill currentCommonSkills;
    CloneSpecialSkill currentSpecialSkills;
};
