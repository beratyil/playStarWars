#include "CharacterSelectScreen.h"

CharacterSelection::CharacterSelection(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.returnMainMenu, SIGNAL(clicked()), this, SLOT(returnMainMenu()));
}

CharacterSelection::~CharacterSelection()
{}

void CharacterSelection::returnMainMenu()
{

}
