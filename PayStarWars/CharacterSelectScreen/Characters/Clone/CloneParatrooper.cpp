#include "CloneParatrooper.h"

CloneParatrooper::CloneParatrooper(QWidget* parent)
{
    ui.setupUi(this);
 
    setCharImage("..\\Resources\\Soldiers\\Clones\\CloneParatrooper.png");

    setDescription();
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

}