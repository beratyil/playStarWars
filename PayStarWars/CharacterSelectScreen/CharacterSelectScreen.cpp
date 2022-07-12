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
