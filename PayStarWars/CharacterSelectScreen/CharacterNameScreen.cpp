#include "CharacterNameScreen.h"

CharacterName::CharacterName(Collection* collection, QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /* TODO: fix background image with coming from Selected Character */
    QImage backGroundImage(":\PlayStarWars\\Resources\\CharacterSelectionScreen\\backGround.jpeg");
    QPainter backGroundPainter;
    backGroundPainter.begin(&backGroundImage);
    backGroundPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    backGroundPainter.fillRect(backGroundImage.rect(), QColor(10, 10, 10, 50));
    backGroundPainter.end();
    ui.backGround->setPixmap(QPixmap::fromImage(backGroundImage));

    connect(ui.returnSelection, SIGNAL(clicked()), this, SIGNAL(returnSelection()));
    connect(ui.continueGame, SIGNAL(clicked()), this, SLOT(setName()));

    connect(ui.returnSelection, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui.continueGame, SIGNAL(clicked()), this, SLOT(close()));

    mCollection = collection;
}

CharacterName::~CharacterName()
{
}

void CharacterName::exit()
{
    this->close();
}

void CharacterName::setName()
{
    QString name = ui.characterName->text();

    mCollection->setName(name);

    emit createSoldier();
}
