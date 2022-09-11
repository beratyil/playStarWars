#pragma once

#include "Soldier.h"
#include "qstring.h"
#include "SoldierUtilities.h"
#include "Attack/DroidAttack.h"
#include "Health.h"

using namespace SoldierSpace;

class Droid : public Soldier, public DroidAttack, public Health
{
public:

    Droid() = default;

    Droid(QString charName, QString lifeForm, SoldierType soldierType, qint16 level, DroidWeapon::Weapon weapon, DroidWeapon::Range range = DroidWeapon::Range::SHORT);

    Droid operator=(const Droid& droid)
    {
        QString lifeForm = droid.getLifeForm();
        SoldierType soldierType = droid.getSoldierType();
        qint16 level = droid.getLevel();

        Type type = droid.getType();

        setType(type);

        setLifeForm(lifeForm);
        setSoldierType(soldierType);

    }

    ~Droid();

    qint16 attack(qint16 abilityType, qint16 attackNumber) override;



private:



};
