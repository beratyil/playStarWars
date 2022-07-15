#include "CloneParatrooper.h"

CloneParatrooper::CloneParatrooper(QWidget* parent)
{
    ui.setupUi(this);
 

    QString imageDir = "..\\Resources\\Soldiers\\Clones\\CloneParatrooper.png";

    QString description = "Clone paratroopers, also known as airborne clones,\n were specialized clone troopers trained for airborne\n operations in the Grand Army of the \nRepublic.In the waning days of the Clone Wars, the \nparatroopers of the 212th Attack Battalion served \nas front line assault units in the \nBattle of Utapau.";
    
    QStringList list;

    prepInfoScreen(imageDir, description, list);

    connect(ui.goBack, &QPushButton::clicked, this, &ICharacterInformationScreen::closed);

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

void CloneParatrooper::test()
{
    emit goBack();
}