#include "Soldier.h"

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

QString Soldier::getLifeForm() const {
    return mLifeForm;
}

void Soldier::setLifeForm(QString lifeForm) {
    mLifeForm = lifeForm;
}

QString Soldier::getSoldierType() const {
    return mSoldierType;
}

void Soldier::setSoldierType(QString soldierType) {
    mSoldierType = soldierType;
}
