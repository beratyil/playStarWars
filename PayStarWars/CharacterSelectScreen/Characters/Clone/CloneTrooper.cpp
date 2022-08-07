#include "CloneTrooper.h"

CloneTrooper::CloneTrooper(QWidget* parent)
    : ICharacterInformationScreen(parent)
{
    QString imageDir = ":\PlayStarWars\\Resources\\Soldiers\\Clones\\CloneTrooper.png";

    QString description = "Clone troopers, also known as Republic troopers, Republic troops, Republic soldiers, Regs, and nicknamed the \"Boys in White,\" were highly trained soldiers in the Grand Army of the Republic.Representing the future of galactic warfare, clones were designed to be far superior to battle droids.";

    QStringList list;

    prepInfoScreen(imageDir, description, list);
}

CloneTrooper::~CloneTrooper()
{
}

void CloneTrooper::prepAttributes(QStringList& attr)
{
    QString armor = "<ul><li>Armor : 2</li>";
    QString health = "<li>Health : 2</li>";
    QString damage = "<li>Damage : 2</li>";
    QString race = "<li>Race : Human</li>";
    QString weapon = "<li>Weapon : Blaster</li></ul>";

    attr.append(armor);
    attr.append(health);
    attr.append(damage);
    attr.append(race);
    attr.append(weapon);
}
