#include "Utilities.h"

ICharacterInformationScreen::ICharacterInformationScreen(Collection* collection, QWidget* parent)
    : QMainWindow(parent)
    , mCollection{collection}
{
    ui.setupUi(this);

    /* Emit Signal For Closing Information Screen and Return to CharacterSelectionScreen */
    connect(ui.goBack, &QPushButton::clicked, this, &ICharacterInformationScreen::goBack);

    /* Open Map, Kill Character Selection and Character Information Screen */
    //connect(ui.select, &QPushButton::clicked, this, &ICharacterInformationScreen::openMapSender);
    connect(ui.select, &QPushButton::clicked, this, &ICharacterInformationScreen::enterCharacterNameScreen);

    /*Collection* collect = static_cast<Collection*>(collection);

    mSoldier = collect->getSoldier();*/
}

void ICharacterInformationScreen::prepInfoScreen(QString imageDir, QString desc, QStringList& attr)
{
    setCharImage(imageDir);

    setDescription(desc);

    ui.attributes->setReadOnly(true);

    setAttributes(attr);
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

    /* In order to fit the paragraph to widget */
    ui.description->setWordWrap(true);
}

void ICharacterInformationScreen::setAttributes(QStringList& attributes)
{
    prepAttributes(attributes);

    ui.attributes->setFrameStyle(QFrame::Panel | QFrame::Plain);

    for (auto it = attributes.begin(); it != attributes.end(); it++) {

        QString attrLine = *it;

        ui.attributes->appendHtml(attrLine);
    }
}

Collection::Collection(Soldier* soldier)
{
    mSoldier = &soldier;
}

Soldier** Collection::getSoldier()
{
    return mSoldier;
}

void Collection::setName(QString name)
{
    mCharName = new QString(name);
}

QString* Collection::getName()
{
    return mCharName;
}
