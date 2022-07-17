#include "CloneSoldier.h"

// @note: CloneAttack class will be implemented

Clone::Clone()
{
    setHealth(4);
    setArmor(3);
    setLifeForm("Human");
    setSoldierType("Clone");
    //attack = new cloneAttack();
}

Clone::Clone(int health, int armor, QString lifeForm, QString soldierType, Weapon weapon)
{
    setHealth(health);
    setArmor(armor);
    setLifeForm(lifeForm);
    setSoldierType(soldierType);
    //attack = new cloneAttack(weapon);
}

void Clone::print() {

    //System.out.println("Weapon: " + attack.weaponString());

}

qint16 Clone::attack()
{
    return qint16(-100);
}