#include "CloneHeavyGunner.h"

CloneHeavyGunner::CloneHeavyGunner(Collection* collection, QWidget* parent)
    : ICharacterInformationScreen(collection, parent)
{
    QString imageDir = ":\PlayStarWars\\Resources\\Soldiers\\Clones\\CloneHeavyGunner.png";

    QString description = "Heavy Gunners were clone troopers in the Grand Army of the Republic that used Z-6 rotary blaster cannons. The troopers had better clone trooper armor than other clones in the army. Due to their heavy blaster, they had superior firepower as well.";

    QStringList list;

    prepInfoScreen(imageDir, description, list);

    mSoldier = collection->getSoldier();
}

CloneHeavyGunner::~CloneHeavyGunner()
{
}

void CloneHeavyGunner::setSoldierAttributes()
{
    QString name = "";
    QString lifeForm = "Human";
    Clone::SoldierType type = Clone::SoldierType::Heavy_Assault;
    CloneWeapon::Weapon weapon = CloneWeapon::Weapon::Z_6_ROTARY_CANON;

    *mSoldier = new Clone(name, lifeForm, type, 1, weapon);
 
    emit continueMap();
}

void CloneHeavyGunner::prepAttributes(QStringList& attr)
{
    QString armor = "<ul><li>Armor : 2</li>";
    QString health = "<li>Health : 5</li>";
    QString damage = "<li>Damage : 5</li>";
    QString race = "<li>Race : Human</li>";
    QString weapon = "<li>Weapon : Blaster Cannon</li></ul>";

    attr.append(armor);
    attr.append(health);
    attr.append(damage);
    attr.append(race);
    attr.append(weapon);
}
