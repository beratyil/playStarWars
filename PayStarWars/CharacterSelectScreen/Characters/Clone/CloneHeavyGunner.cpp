#include "CloneHeavyGunner.h"

CloneHeavyGunner::CloneHeavyGunner(QWidget* parent)
{
    ui.setupUi(this);
 
    setCharImage("..\\Resources\\Soldiers\\Clones\\CloneHeavyGunner.png");

    setDescription();
    
    ui.attributes->setReadOnly(true);
    QStringList list;
    setAttributes(list); 
}

CloneHeavyGunner::~CloneHeavyGunner()
{
}

void CloneHeavyGunner::setCharImage(QString imageDir)
{
    QPixmap heroImage(imageDir);
    
    ui.heroImage->setPixmap(heroImage);
}

void CloneHeavyGunner::setDescription()
{
    QString descrition = "Heavy Gunners were clone troopers in the Grand Army\nof the Republic that used Z-6 rotary\nblaster cannons. The troopers had better clone\ntrooper armor than other clones in the army.\nDue to their heavy blaster, they had superior\nfirepower as well.";
    
    ui.description->setFrameStyle(QFrame::Panel | QFrame::Plain);
    ui.description->setText(descrition);
    ui.description->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

void CloneHeavyGunner::setAttributes(QStringList attributes)
{
    QString exampleLine = "<ul><li>Coffee< / li><li>Tea< / li>< / ul>";

    QStringList attrList = prepAttributes();

    ui.attributes->setFrameStyle(QFrame::Panel | QFrame::Plain);

    for (auto it = attrList.begin(); it != attrList.end(); it++) {
        
        QString attrLine = *it;

        ui.attributes->appendHtml(attrLine);
    }
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
