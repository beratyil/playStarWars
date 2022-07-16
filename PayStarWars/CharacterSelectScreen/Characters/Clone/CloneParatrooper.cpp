#include "CloneParatrooper.h"

CloneParatrooper::CloneParatrooper(QWidget* parent)
    : ICharacterInformationScreen(parent)
{
    QString imageDir = "..\\Resources\\Soldiers\\Clones\\CloneParatrooper.png";

    QString description = "Clone paratroopers, also known as airborne clones, were specialized clone troopers trained for airborneoperations in the Grand Army of the Republic.In the waning days of the Clone Wars, the paratroopers of the 212th Attack Battalion served as front line assault units in the Battle of Utapau.";
    
    QStringList list;

    prepInfoScreen(imageDir, description, list);

}

CloneParatrooper::~CloneParatrooper()
{
}

void CloneParatrooper::prepAttributes(QStringList& attr)
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
