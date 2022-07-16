#include "CloneHeavyGunner.h"

CloneHeavyGunner::CloneHeavyGunner(QWidget* parent)
    : ICharacterInformationScreen(parent)
{
    QString imageDir = "..\\Resources\\Soldiers\\Clones\\CloneHeavyGunner.png";

    QString description = "Heavy Gunners were clone troopers in the Grand Army\nof the Republic that used Z-6 rotary\nblaster cannons. The troopers had better clone\ntrooper armor than other clones in the army.\nDue to their heavy blaster, they had superior\nfirepower as well.";

    QStringList list;

    prepInfoScreen(imageDir, description, list);
}

CloneHeavyGunner::~CloneHeavyGunner()
{
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
