#pragma once

#include "Soldier.h"
#include "qstring.h"
#include "SoldierUtilities.h"
#include "Attack/CloneAttack.h"

using namespace SoldierSpace;

class Clone : public Soldier, public CloneAttack
{
public:
    Clone() = default;

    Clone(qint16 health, qint16 armor, QString lifeForm, QString soldierType, CloneWeapon::Weapon weapon, CloneWeapon::Range range = CloneWeapon::Range::SHORT);

    Clone operator=(const Clone& clone)
    {
        qint16 health = clone.getHealth();
        qint16 armor = clone.getArmor();
        QString lifeForm = clone.getLifeForm();
        QString soldierType = clone.getSoldierType();

        setHealth(health);
        setArmor(armor);
        setLifeForm(lifeForm);
        setSoldierType(soldierType);
    }

    ~Clone();

    qint16 attack(qint16 abilityType, qint16 attackNumber) override;

private:

};
