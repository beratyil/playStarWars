#include "CloneHeavyGunner.h"

CloneHeavyGunner::CloneHeavyGunner(QWidget* parent)
{
    ui.setupUi(this);
 
    setCharImage("..\\Resources\\Soldiers\\Clones\\CloneHeavyGunner.png");

    QString description = "Heavy Gunners were clone troopers in the Grand Army\nof the Republic that used Z-6 rotary\nblaster cannons. The troopers had better clone\ntrooper armor than other clones in the army.\nDue to their heavy blaster, they had superior\nfirepower as well.";

    setDescription(description);
    
    ui.attributes->setReadOnly(true);
    
    QStringList list;
    setAttributes(list); 
}

CloneHeavyGunner::~CloneHeavyGunner()
{
}

QStringList CloneHeavyGunner::prepAttributes()
{
    QStringList returnAttrList;
    
    QString armor = "<ul><li>Armor : 2</li>";
    QString health = "<li>Armor : 5</li>";
    QString damage = "<li>Damage : 5</li>";
    QString race = "<li>Race : Human</li>";
    QString weapon = "<li>Weapon : Blaster Cannon</li></ul>";

    returnAttrList.append(armor);
    returnAttrList.append(health);
    returnAttrList.append(damage);
    returnAttrList.append(race);
    returnAttrList.append(weapon);

    return returnAttrList;
}
