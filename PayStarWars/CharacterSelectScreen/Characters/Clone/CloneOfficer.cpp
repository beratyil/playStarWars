#include "CloneOfficer.h"

CloneOfficer::CloneOfficer(Collection* collection, QWidget* parent)
    : ICharacterInformationScreen(collection, parent)
{
    QString imageDir = ":\PlayStarWars\\Resources\\Soldiers\\Clones\\CloneOfficer.png";

    QString description = "Clone paratroopers, also known as airborne clones, were specialized clone troopers trained for airborneoperations in the Grand Army of the Republic.In the waning days of the Clone Wars, the paratroopers of the 212th Attack Battalion served as front line assault units in the Battle of Utapau.";
    
    QStringList list;

    prepInfoScreen(imageDir, description, list);

    mSoldier = collection->getSoldier();
}

CloneOfficer::~CloneOfficer()
{
}

void CloneOfficer::setSoldierAttributes()
{
    QString name = "";
    QString lifeForm = "Human";
    Clone::SoldierType type = Clone::SoldierType::Officer;
    CloneWeapon::Weapon weapon = CloneWeapon::Weapon::DC_15A_RIFLE;
    
    *mSoldier = new Clone(name, lifeForm, type, 1, weapon);

    emit continueMap();
}

void CloneOfficer::prepAttributes(QStringList& attr)
{
    QString armor = "<ul><li>Armor : 1</li>";
    QString health = "<li>Health : 4</li>";
    QString damage = "<li>Damage : 2</li>";
    QString race = "<li>Race : Human</li>";
    QString weapon = "<li>Weapon : Blaster</li></ul>";

    attr.append(armor);
    attr.append(health);
    attr.append(damage);
    attr.append(race);
    attr.append(weapon);
}
