// @Explaining: This class for every Clone Attack
// Simple Attack
//      hand to hand combat
//      blaster attack
// Special Attack
//      handgranade
//      headshot

#pragma once

#include "SoldierUtilities.h"

using SoldierSpace::DroidCommonSkill;
using SoldierSpace::DroidSpecialSkill;
using SoldierSpace::DroidWeapon;

//CloneAttack Class
//Wrapps every attack operation
//Common Skills, Special Skills or Normal Attack
class DroidAttack
{

public:

    typedef enum skillType {
        commonSkill,
        specialSkill
    };

    DroidAttack() = default;

    DroidAttack(DroidWeapon::Weapon newWeapon, DroidWeapon::Range range);
    DroidAttack(DroidWeapon newWeapon);
    ~DroidAttack();

    void updateWeapon(DroidWeapon newWeapon);

    DroidWeapon getWeapon();

    QVector<DroidCommonSkill::CommonSkill> getCommonSkills();

    QVector<DroidSpecialSkill::Equipment> getSpecialSkills();

    QStringList getCommonSkillsString();

    QStringList getSpecialSkillsString();

    bool addSkill(skillType skillType, qint16 skill);

protected:
    qint16 attack(DroidCommonSkill::CommonSkill commonSkill);

    qint16 attack(DroidSpecialSkill::Equipment specialSkill);

    DroidWeapon mCurrentWeapon;
    DroidCommonSkill mCurrentCommonSkills;
    DroidSpecialSkill mCurrentSpecialSkills;


};