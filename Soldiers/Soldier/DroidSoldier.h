#pragma once

#include "Soldier.h"
#include "qstring.h"
#include "SoldierUtilities.h"
#include "Attack/DroidAttack.h"

using namespace SoldierSpace;

class Droid : public Soldier, public DroidAttack
{
public:

    Droid() = default;

    Droid(qint16 health, qint16 armor, QString lifeForm, SoldierType soldierType, DroidWeapon::Weapon weapon, DroidWeapon::Range range = DroidWeapon::Range::SHORT);

    Droid operator=(const Droid& droid)
    {
        qint16 health = droid.getHealth();
        qint16 armor = droid.getArmor();
        QString lifeForm = droid.getLifeForm();
        SoldierType soldierType = droid.getSoldierType();

        Type type = droid.getType();

        setType(type);

        setHealth(health);
        setArmor(armor);
        setLifeForm(lifeForm);
        setSoldierType(soldierType);
    }

    ~Droid();

    qint16 attack(qint16 abilityType, qint16 attackNumber) override;



private:



};
