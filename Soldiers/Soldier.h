#pragma once

#include "soldier_global.h"
#include "qstring.h"
#include "qstringlist.h"

//Soldier Abstract Class
//Used as pointer for every type of Soldier Classes,
//e.x Clone, Droid, Jedi or Sith
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
    qint16 mHealth;
    qint16 mArmor;

    QString mLifeForm;
    QString mSoldierType;

};
