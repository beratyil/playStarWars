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

    int getHealth() const;

    void setHealth(int health);

    int getArmor() const;

    void setArmor(int armor);

    QString getLifeForm() const;

    void setLifeForm(QString lifeForm);

    QString getSoldierType() const;

    void setSoldierType(QString soldierType);

    virtual qint16 attack(qint16 abilityType, qint16 attackNumber) = 0;

private:
    qint16 mHealth;
    qint16 mArmor;

    QString mLifeForm;
    QString mSoldierType;

};
