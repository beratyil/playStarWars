#include "PayStarWars.h"
#include "CharacterSelectScreen.h"

PayStarWars::PayStarWars(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.exitButton, &QPushButton::clicked, this, &PayStarWars::exit);
    //connect(ui.exitButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    connect(ui.newGameButton, SIGNAL(clicked()), this, SLOT(openNewGame()));
    
    connect(ui.loadGameButton, SIGNAL(toggled()), this, SLOT(exit()));

    QIcon iconNewGame("..\\Resources\\Menu\\playButton.png");
    ui.newGameButton->setIcon(iconNewGame);

    QIcon iconExit("..\\Resources\\Menu\\exitButton.png");
    ui.exitButton->setIcon(iconExit);

    QPixmap pixmapLogo("..\\Resources\\Menu\\StarWars.png");
    ui.backGround->setPixmap(pixmapLogo);

}

PayStarWars::~PayStarWars()
{}

void PayStarWars::openNewGame()
{
    CharacterSelection* newCharacterSelectScreen = nullptr;
    
    hide();

    newCharacterSelectScreen = new CharacterSelection();
    newCharacterSelectScreen->show();
}

void PayStarWars::exit()
{
    QCoreApplication::exit();
}
