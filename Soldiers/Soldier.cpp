#include "Soldier.h"

Soldier::Soldier()
{
}

int Soldier::getHealth() {
    return health;
}

void Soldier::setHealth(int health) {
    this->health = health;
}

int Soldier::getArmor() {
    return armor;
}

void Soldier::setArmor(int armor) {
    this->armor = armor;
}

QString Soldier::getLifeForm() {
    return lifeForm;
}

void Soldier::setLifeForm(QString lifeForm) {
    this->lifeForm = lifeForm;
}

QString Soldier::getSoldierType() {
    return soldierType;
}

void Soldier::setSoldierType(QString soldierType) {
    this->soldierType = soldierType;
}
