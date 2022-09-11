#include "PlayStarWars.h"

PlayStarWars::PlayStarWars(QWidget *parent)
    : QMainWindow(parent)
    , mCharacterSelectScreen(nullptr)
    , mMap(nullptr)
    , mSoldier{nullptr}
    , mCollection{nullptr}
{
    ui.setupUi(this);

    connect(ui.exitButton, &QPushButton::clicked, this, &PlayStarWars::exit);
    //connect(ui.exitButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    connect(ui.newGameButton, SIGNAL(clicked()), this, SLOT(openNewGame()));
    
    connect(ui.loadGameButton, SIGNAL(clicked()), this, SLOT(startGame()));

    QIcon iconNewGame(":\\PlayStarWars\\Resources\\Menu\\playButton.png");
    ui.newGameButton->setIcon(iconNewGame);

    QIcon iconLoadGame(":\\PlayStarWars\\Resources\\Menu\\playButton.png");
    ui.loadGameButton->setIcon(iconLoadGame);

    QIcon iconExit(":\\PlayStarWars\\Resources\\Menu\\exitButton.png");
    ui.exitButton->setIcon(iconExit);

    QPixmap pixmapLogo(":\\PlayStarWars\\Resources\\Menu\\StarWars.png");
    ui.backGround->setPixmap(pixmapLogo);

    QString defaultSoldierName = "Default";
    mCollection = new Collection(mSoldier, defaultSoldierName);
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
    newCharacterSelectScreen = new CharacterSelection(mCollection);
    newCharacterSelectScreen->show();

    mCharacterSelectScreen = newCharacterSelectScreen;

    /* Create Return Path From Character Select Screen to Main Menu */
    connect(mCharacterSelectScreen, &CharacterSelection::returnMainMenu, this, &PlayStarWars::returnMainMenu);
    
    connect(mCharacterSelectScreen, &CharacterSelection::openMapSender, this, &PlayStarWars::startGame);
    
    /* @note: Destroy temp pointer */
    newCharacterSelectScreen = nullptr;
    delete newCharacterSelectScreen;
}

void PlayStarWars::returnMainMenu()
{
    this->setVisible(true);

    killCharSelect();
}

void PlayStarWars::startGame()
{
    /* Access Char Info Screen Via Char Select Screen */
    if (mCharacterSelectScreen != nullptr) {

        mCharacterSelectScreen->closeCharacterInformationScreen();

        killCharSelect();
    }

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

void PlayStarWars::killCharSelect()
{
    mCharacterSelectScreen->exit();

    delete mCharacterSelectScreen;

    mCharacterSelectScreen = nullptr;
}

void PlayStarWars::exit()
{
    QCoreApplication::exit();
}
