#pragma once

#include "soldier_global.h"
#include "qstring.h"

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

    void print();

    virtual qint16 attack() = 0;

private:
    qint16 health;
    qint16 armor;

    QString lifeForm;
    QString soldierType;
};
