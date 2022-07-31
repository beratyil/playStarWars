#pragma once

#include "soldier_global.h"
#include "qstring.h"
#include "qstringlist.h"

class SOLDIER_EXPORT Soldier
{
public:
    Soldier();

    int getHealth();

    void setHealth(int health);

    int getArmor();

    void setArmor(int armor);

    QString getLifeForm();

    void setLifeForm(QString lifeForm);

    QString getSoldierType();

    void setSoldierType(QString soldierType);

    virtual qint16 attack(qint16 abilityType, qint16 attackNumber) = 0;

private:
    qint16 health;
    qint16 armor;

    QString lifeForm;
    QString soldierType;

};
