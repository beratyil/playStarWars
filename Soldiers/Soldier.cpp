#include "Soldier.h"

Soldier::Soldier()
{
}

int Soldier::getHealth() {
    return mHealth;
}

void Soldier::setHealth(int health) {
    mHealth = health;
}

int Soldier::getArmor() {
    return mArmor;
}

void Soldier::setArmor(int armor) {
    mArmor = armor;
}

QString Soldier::getLifeForm() {
    return mLifeForm;
}

void Soldier::setLifeForm(QString lifeForm) {
    mLifeForm = lifeForm;
}

QString Soldier::getSoldierType() {
    return mSoldierType;
}

void Soldier::setSoldierType(QString soldierType) {
    mSoldierType = soldierType;
}
