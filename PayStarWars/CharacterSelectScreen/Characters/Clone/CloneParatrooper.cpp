#include "CloneParatrooper.h"

CloneParatrooper::CloneParatrooper(QWidget* parent)
{
    ui.setupUi(this);
 
    setCharImage("..\\Resources\\Soldiers\\Clones\\CloneParatrooper.png");

    setDescription();
    
    ui.attributes->setReadOnly(true);
    QStringList list;
    setAttributes(list);
}

CloneParatrooper::~CloneParatrooper()
{
}

void CloneParatrooper::setCharImage(QString imageDir)
{
    QPixmap heroImage(imageDir);
    
    ui.heroImage->setPixmap(heroImage);
}

void CloneParatrooper::setDescription()
{
    QString descrition = "Clone paratroopers, also known as airborne clones,\n were specialized clone troopers trained for airborne\n operations in the Grand Army of the \nRepublic.In the waning days of the Clone Wars, the \nparatroopers of the 212th Attack Battalion served \nas front line assault units in the \nBattle of Utapau.";
    
    ui.description->setFrameStyle(QFrame::Panel | QFrame::Plain);
    ui.description->setText(descrition);
    ui.description->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

void CloneParatrooper::setAttributes(QStringList attributes)
{
    QString exampleLine = "<ul><li>Coffee< / li><li>Tea< / li>< / ul>";

    QStringList attrList = prepAttributes();

    ui.attributes->setFrameStyle(QFrame::Panel | QFrame::Plain);

    for (auto it = attrList.begin(); it != attrList.end(); it++) {
        
        QString attrLine = *it;

        ui.attributes->appendHtml(attrLine);
    }
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
