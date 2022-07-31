#pragma once

#include "..\Soldier.h"
#include "qstring.h"
#include "..\\Utilities.h"
#include "../Attack/CloneAttack.h"

using namespace SoldierSpace;

class Clone : public Soldier, public CloneAttack
{
public:
    Clone() = default;

    Clone(qint16 health, qint16 armor, QString lifeForm, QString soldierType, CloneWeapon::Weapon weapon);

    ~Clone();

    qint16 attack(qint16 abilityType, qint16 attackNumber) override;

private:

};
