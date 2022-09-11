#include "CharacterSelectScreen.h"

CharacterSelection::CharacterSelection(void* collection, QWidget* parent)
    : QMainWindow(parent)
    , mCharInfoScreen(nullptr)
    , mCollection{collection}
{
    ui.setupUi(this);
    
    connect(ui.returnMainMenu, SIGNAL(clicked()), this, SIGNAL(returnMainMenu()));

    /* @note make background color more transparent */
    QImage backGroundImage(":\PlayStarWars\\Resources\\CharacterSelectionScreen\\backGround.jpeg");
    QPainter backGroundPainter;
    backGroundPainter.begin(&backGroundImage);
    backGroundPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    backGroundPainter.fillRect(backGroundImage.rect(), QColor(10, 10, 10, 50));
    backGroundPainter.end();
    ui.backGround->setPixmap(QPixmap::fromImage(backGroundImage));

    connect(ui.trooper, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));
    connect(ui.paratrooper, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));
    connect(ui.heavyGunner, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));
    connect(ui.sharpShooter, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));
}

CharacterSelection::~CharacterSelection()
{
}

void CharacterSelection::exit()
{
    this->close();
}

void CharacterSelection::openCharacterInformationScreen()
{
    /* @warning: Using sender function violates the modularity of oop principles. Look at the Documentation of Qt */
    QObject* sender = QObject::sender();
    
    /* @note: get name of the object */
    QString objectName = sender->objectName();

    ICharacterInformationScreen* infoScreen = nullptr;

    if (objectName == "paratrooper") {
        infoScreen = new CloneParatrooper(mCollection);
    }
    else if (objectName == "heavyGunner") {
        infoScreen = new CloneHeavyGunner(mCollection);
    }
    else if (objectName == "sharpShooter") {
        infoScreen = new CloneSharpShooter(mCollection);
    }
    else if (objectName == "trooper") {
        infoScreen = new CloneTrooper(mCollection);
    }
    else {
        
    }

    mCharInfoScreen = infoScreen;

    infoScreen = nullptr;
    delete infoScreen;

    if (mCharInfoScreen != nullptr) {

        connect(mCharInfoScreen, &ICharacterInformationScreen::goBack, this, &CharacterSelection::closeCharacterInformationScreen);
        connect(mCharInfoScreen, &ICharacterInformationScreen::openMapSender, this, &CharacterSelection::openMapSender);
        
        mCharInfoScreen->show();
    }
}

void CharacterSelection::closeCharacterInformationScreen()
{
    mCharInfoScreen->close();

    delete mCharInfoScreen;
    mCharInfoScreen = nullptr;
}
