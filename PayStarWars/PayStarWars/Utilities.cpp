#include "Utilities.h"

ICharacterInformationScreen::ICharacterInformationScreen(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.select, &QPushButton::clicked, this, &ICharacterInformationScreen::testSignal);
    
    connect(this, &ICharacterInformationScreen::testSignal, this, &ICharacterInformationScreen::closed);
}

void ICharacterInformationScreen::prepInfoScreen(QString imageDir, QString desc, QStringList& attr)
{
    setCharImage(imageDir);

    setDescription(desc);

    ui.attributes->setReadOnly(true);

    setAttributes(attr);
}

void ICharacterInformationScreen::closed()
{
    emit goBack();

    this->close();
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

void ICharacterInformationScreen::setAttributes(QStringList& attributes)
{
    prepAttributes(attributes);

    ui.attributes->setFrameStyle(QFrame::Panel | QFrame::Plain);

    for (auto it = attributes.begin(); it != attributes.end(); it++) {

        QString attrLine = *it;

        ui.attributes->appendHtml(attrLine);
    }
}
