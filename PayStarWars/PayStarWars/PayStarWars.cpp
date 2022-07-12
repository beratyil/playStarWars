#include "PayStarWars.h"

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

    mCharacterSelectScreen = nullptr;
}

PayStarWars::~PayStarWars()
{}

void PayStarWars::openNewGame()
{
    /* Create object for Character Select Screen */
    CharacterSelection* newCharacterSelectScreen = nullptr;
    
    /* Hide Main Menu */
    hide();

    /* Show Character Select Screen */
    newCharacterSelectScreen = new CharacterSelection();
    newCharacterSelectScreen->show();

    mCharacterSelectScreen = newCharacterSelectScreen;

    /* Create Return Path From Character Select Screen to Main Menu */
    connect(mCharacterSelectScreen, &CharacterSelection::returnMainMenuSignal, this, &PayStarWars::openMainMenuAgain);
    
    /* @note: Destroy the dynamically created object */
    newCharacterSelectScreen = nullptr;
    delete newCharacterSelectScreen;
}

void PayStarWars::openMainMenuAgain()
{
    this->setVisible(true);

    mCharacterSelectScreen->exit();

    //delete mCharacterSelectScreen;
}

void PayStarWars::exit()
{
    QCoreApplication::exit();
}
