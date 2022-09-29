#include "CloneSharpShooter.h"

CloneSharpShooter::CloneSharpShooter(Collection* collection, QWidget* parent)
    : ICharacterInformationScreen(collection, parent)
{
    QString imageDir = ":\PlayStarWars\\Resources\\Soldiers\\Clones\\CloneSharpshooter.png";

    QString description = "Clone sharpshooters, also known as clone snipers, or Clone Specialists, were a specialized variant of clone troopers who served in the Grand Army of the Galactic Republic during the Clone Wars.Due to their additional training in long range marksmanship, their ability to hit targets at extreme distance was far superior to that of regular troopers.";
    
    QStringList list;

    prepInfoScreen(imageDir, description, list);
}

CloneSharpShooter::~CloneSharpShooter()
{
}

void CloneSharpShooter::setSoldierAttributes()
{
    QString name = "";
    QString lifeForm = "Human";
    Clone::SoldierType type = Clone::SoldierType::Sniper;
    CloneWeapon::Weapon weapon = CloneWeapon::Weapon::DC_15X_SNIPER;

    *mSoldier = new Clone(name, lifeForm, type, 1, weapon);

    emit continueMap();
}

void CloneSharpShooter::prepAttributes(QStringList& attr)
{
    QString armor = "<ul><li>Armor : 2</li>";
    QString health = "<li>Health : 2</li>";
    QString damage = "<li>Damage : 5</li>";
    QString race = "<li>Race : Human</li>";
    QString weapon = "<li>Weapon : Blaster Sniper</li></ul>";

    attr.append(armor);
    attr.append(health);
    attr.append(damage);
    attr.append(race);
    attr.append(weapon);
}
