#include "PlayStarWars.h"

PlayStarWars::PlayStarWars(QWidget *parent)
    : QMainWindow(parent)
    , mCharacterSelectScreen(nullptr)
    , mMap(nullptr)
{
    ui.setupUi(this);

    connect(ui.exitButton, &QPushButton::clicked, this, &PlayStarWars::exit);
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

PlayStarWars::~PlayStarWars()
{}

void PlayStarWars::openNewGame()
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
    connect(mCharacterSelectScreen, &CharacterSelection::returnMainMenu, this, &PlayStarWars::returnMainMenu);
    
    connect(mCharacterSelectScreen, &CharacterSelection::openMapSender, this, &PlayStarWars::killCharInfoScreen);
    
    /* @note: Destroy temp pointer */
    newCharacterSelectScreen = nullptr;
    delete newCharacterSelectScreen;
}

void PlayStarWars::returnMainMenu()
{
    this->setVisible(true);

    mCharacterSelectScreen->exit();

    delete mCharacterSelectScreen;
    
    mCharacterSelectScreen = nullptr;
}

void PlayStarWars::killCharInfoScreen()
{
    /* Access Char Info Screen Via Char Select Screen */
    mCharacterSelectScreen->closeCharacterInformationScreen();

    //@note: update returnMainMenu function. Delete and nullptr assign operation should be done in a one class
    //returnMainMenu();
    mCharacterSelectScreen->exit();

    delete mCharacterSelectScreen;

    mCharacterSelectScreen = nullptr;

    mMap = new Map();
    connect(mMap, &Map::returnMainMenu, this, &PlayStarWars::closeMap);
    
    mMap->show();
}

void PlayStarWars::closeMap()
{
    mMap->close();

    delete mMap;
    mMap = nullptr;

    setVisible(true);
}

void PlayStarWars::exit()
{
    QCoreApplication::exit();
}
