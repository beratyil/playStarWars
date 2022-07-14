#include "CloneParatrooper.h"

CloneParatrooper::CloneParatrooper(QWidget* parent)
{
    ui.setupUi(this);
 
    setCharImage("..\\Resources\\Soldiers\\Clones\\CloneParatrooper.png");

    QString description = "Clone paratroopers, also known as airborne clones,\n were specialized clone troopers trained for airborne\n operations in the Grand Army of the \nRepublic.In the waning days of the Clone Wars, the \nparatroopers of the 212th Attack Battalion served \nas front line assault units in the \nBattle of Utapau.";
    setDescription(description);
    
    ui.attributes->setReadOnly(true);
    
    QStringList list;
    setAttributes(list);
}

CloneParatrooper::~CloneParatrooper()
{
}

QStringList CloneParatrooper::prepAttributes()
{
    QStringList returnAttrList;
    
    QString armor = "<ul><li>Armor : 1</li>";
    QString health = "<li>Armor : 4</li>";
    QString damage = "<li>Damage : 2</li>";
    QString race = "<li>Race : Human</li>";
    QString weapon = "<li>Weapon : Blaster</li></ul>";

    returnAttrList.append(armor);
    returnAttrList.append(health);
    returnAttrList.append(damage);
    returnAttrList.append(race);
    returnAttrList.append(weapon);

    return returnAttrList;
}
