// @Explaining: This class for every Clone Attack
// Simple Attack
//      hand to hand combat
//      blaster attack
// Special Attack
//      handgranade
//      headshot

#pragma once

#include "SoldierUtilities.h"

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

    CloneAttack(CloneWeapon::Weapon newWeapon, CloneWeapon::Range range);
    CloneAttack(CloneWeapon newWeapon);
    ~CloneAttack();

    void updateWeapon(CloneWeapon newWeapon);

    CloneWeapon getWeapon();

    QString getWeaponStr();

    QVector<CloneCommonSkill::CommonSkill> getCommonSkills();

    QVector<CloneSpecialSkill::Equipment> getSpecialSkills();

    QStringList getCommonSkillsString();

    QStringList getSpecialSkillsString();

    bool addSkill(skillType skillType, qint16 skill);

protected:
    qint16 attack(CloneCommonSkill::CommonSkill commonSkill);

    qint16 attack(CloneSpecialSkill::Equipment specialSkill);

    CloneWeapon mCurrentWeapon;
    CloneCommonSkill mCurrentCommonSkills;
    CloneSpecialSkill mCurrentSpecialSkills;

    
};
