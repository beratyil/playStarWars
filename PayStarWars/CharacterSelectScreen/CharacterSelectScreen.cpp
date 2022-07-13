#include "CharacterSelectScreen.h"

CharacterSelection::CharacterSelection(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.returnMainMenu, SIGNAL(clicked()), this, SLOT(returnMainMenuSlot()));

    /* @note make background color more transparent */
    QImage backGroundImage("..\\Resources\\CharacterSelectionScreen\\backGround.jpeg");
    QPainter backGroundPainter;
    backGroundPainter.begin(&backGroundImage);
    backGroundPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    backGroundPainter.fillRect(backGroundImage.rect(), QColor(10, 10, 10, 50));
    backGroundPainter.end();
    ui.backGround->setPixmap(QPixmap::fromImage(backGroundImage));

    connect(ui.paratrooper, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));
    connect(ui.heavyGunner, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));
    connect(ui.sharpShooter, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));
    connect(ui.commander, SIGNAL(clicked()), this, SLOT(openCharacterInformationScreen()));

}

CharacterSelection::~CharacterSelection()
{
}

void CharacterSelection::exit()
{
    this->close();
}

void CharacterSelection::returnMainMenuSlot()
{
    emit returnMainMenuSignal();
}

void CharacterSelection::openCharacterInformationScreen()
{
    /* @warning: Using sender function violates the modularity of oop principles. Look at the Documentation of Qt */
    QObject* sender = QObject::sender();
    
    /* @note: get name of the object */
    QString objectName = sender->objectName();

    ICharacterInformationScreen* infoScreen = nullptr;

    if (objectName == "paratrooper") {
        infoScreen = new CloneParatrooper();
    }
    else {
        
    }

    infoScreen->show();
}

