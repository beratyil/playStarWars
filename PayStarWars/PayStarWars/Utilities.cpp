#include "Utilities.h"

ICharacterInformationScreen::ICharacterInformationScreen(QWidget* parent)
    : QMainWindow(parent)
{

}

void ICharacterInformationScreen::setCharImage(QString imageDir)
{
    QPixmap heroImage(imageDir);

    ui.heroImage->setPixmap(heroImage);
}

void ICharacterInformationScreen::setDescription(QString description)
{
    ui.description->setFrameStyle(QFrame::Panel | QFrame::Plain);
    ui.description->setText(description);
    ui.description->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

void ICharacterInformationScreen::setAttributes(QStringList attributes)
{
    QStringList attrList = prepAttributes();

    ui.attributes->setFrameStyle(QFrame::Panel | QFrame::Plain);

    for (auto it = attrList.begin(); it != attrList.end(); it++) {

        QString attrLine = *it;

        ui.attributes->appendHtml(attrLine);
    }
}
