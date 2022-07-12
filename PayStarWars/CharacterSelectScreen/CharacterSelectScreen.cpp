#include "CharacterSelectScreen.h"

CharacterSelection::CharacterSelection(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.returnMainMenu, SIGNAL(clicked()), this, SLOT(returnMainMenuSlot()));

    QPixmap pixmapBackGround("..\\Resources\\CharacterSelectionScreen\\backGround.jpeg");
    ui.backGround->setPixmap(pixmapBackGround);
}

CharacterSelection::~CharacterSelection()
{
    QCoreApplication::exit();
}

void CharacterSelection::exit()
{
    this->close();
}

void CharacterSelection::returnMainMenuSlot()
{
    emit returnMainMenuSignal();
}
