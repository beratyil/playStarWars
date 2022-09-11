#pragma once

#include "Soldier.h"
#include "Health.h"
#include "qstring.h"
#include "SoldierUtilities.h"
#include "Attack/CloneAttack.h"

using namespace SoldierSpace;

class Clone : public Soldier, public CloneAttack, public Health
{
public:
    Clone() = default;

    Clone(QString charName, QString lifeForm, SoldierType soldierType, qint16 level, CloneWeapon::Weapon weapon, CloneWeapon::Range range = CloneWeapon::Range::SHORT);

    Clone operator=(const Clone& clone)
    {
        QString lifeForm = clone.getLifeForm();
        SoldierType soldierType = clone.getSoldierType();
        qint16 level = clone.getLevel();
        
        Type type = clone.getType();

        setType(type);

        setLifeForm(lifeForm);
        setSoldierType(soldierType);

        setLevel(level);
    }

    ~Clone();

    qint16 attack(qint16 abilityType, qint16 attackNumber) override;

private:

};
