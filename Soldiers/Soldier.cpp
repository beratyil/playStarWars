#include "Soldier.h"

typedef Soldier::SoldierType SoldierType;
typedef Soldier::Type Type;

Soldier::Soldier()
    : mLifeForm{}
    , mSoldierType{}
    , mHealth{0}
    , mArmor{0}
{}

int Soldier::getHealth() const {
    return mHealth;
}

void Soldier::setHealth(int health) {
    mHealth = health;
}

int Soldier::getArmor() const {
    return mArmor;
}

void Soldier::setArmor(int armor) {
    mArmor = armor;
}

void Soldier::setType(Type type)
{
    mType = type;
}

Soldier::Type Soldier::getType() const
{
    return mType;
}

QString Soldier::getLifeForm() const {
    return mLifeForm;
}

void Soldier::setLifeForm(QString lifeForm) {
    mLifeForm = lifeForm;
}

SoldierType Soldier::getSoldierType() const {
    return mSoldierType;
}

bool Soldier::setSoldierType(SoldierType soldierType)
{
    bool isSet = false;

    switch (mType) {
        case(Type::Clone): {
            if (qint16(soldierType) < 300 && qint16(soldierType) >= 200) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        case(Type::Droid): {
            if (qint16(soldierType) < 200 && qint16(soldierType) >= 0) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        case(Type::Jedi): {
            if (qint16(soldierType) < 400 && qint16(soldierType) >= 300) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        case(Type::Sith): {
            if (qint16(soldierType) >= 400) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        default:
            isSet = false;
    }

    return isSet;
}
