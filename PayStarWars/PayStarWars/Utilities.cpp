#include "Utilities.h"

ICharacterInformationScreen::ICharacterInformationScreen(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /* Emit Signal For Closing Information Screen and Return to CharacterSelectionScreen */
    connect(ui.goBack, &QPushButton::clicked, this, &ICharacterInformationScreen::goBack);

    /* Open Map, Kill Character Selection and Character Information Screen */
    //connect(ui.select, &QPushButton::clicked, this, &ICharacterInformationScreen::openMapSender);
    connect(ui.select, &QPushButton::clicked, this, &ICharacterInformationScreen::openMap);
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

void ICharacterInformationScreen::openMap()
{
    mMap = new Map(this);

    emit mapObjectSender(mMap);
    emit openMapSender();
}

void ICharacterInformationScreen::closeMap()
{
    delete mMap;
    mMap = nullptr;
}
