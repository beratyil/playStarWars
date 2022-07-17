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

    void print() {

        /* This codes was designed to be a console application. For gui application it will be decided how to 
        print these information to the screen. */

        /*std::cout << "Health: " + health << std::endl;
        std::cout << "armor: " + armor << std::endl;
        std::cout << "lifeForm: " + lifeForm << std::endl;
        std::cout << "soldierType: " + soldierType << std::endl;*/

    }

    virtual qint16 attack() = 0;

private:
    qint16 health;
    qint16 armor;

    QString lifeForm;
    QString soldierType;
};
