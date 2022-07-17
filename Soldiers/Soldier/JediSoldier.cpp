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

void Soldier::print() {

    /* This codes was designed to be a console application. For gui application it will be decided how to
    print these information to the screen. */

    /*std::cout << "Health: " + health << std::endl;
    std::cout << "armor: " + armor << std::endl;
    std::cout << "lifeForm: " + lifeForm << std::endl;
    std::cout << "soldierType: " + soldierType << std::endl;*/

}