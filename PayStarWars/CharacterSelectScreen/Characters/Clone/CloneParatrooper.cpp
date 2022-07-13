#include "CloneParatrooper.h"

CloneParatrooper::CloneParatrooper(QWidget* parent)
{
    ui.setupUi(this);
 
    setCharImage("..\\Resources\\Soldiers\\Clones\\CloneParatrooper.png");
}

CloneParatrooper::~CloneParatrooper()
{
}

void CloneParatrooper::setCharImage(QString imageDir)
{
    QPixmap heroImage(imageDir);
    ui.heroImage->setPixmap(heroImage);
}

void CloneParatrooper::setDescription(QString description)
{

}

void CloneParatrooper::setAttributes(QStringList attributes)
{

}