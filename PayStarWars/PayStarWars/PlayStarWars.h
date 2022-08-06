#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PayStarWars.h"
#include "CharacterSelectScreen.h"
#include "Map.h"

class PlayStarWars : public QMainWindow
{
    Q_OBJECT

public:
    PlayStarWars(QWidget *parent = nullptr);
    ~PlayStarWars();

signals:
    void clicked();

public slots:
    void exit();
    void openNewGame();
    void returnMainMenu();
    
    /*
    Kill all the screens
    1.Kill Character Information Screen
    2.Kill Character Selection Screen
    */
    void killCharInfoScreen();

    void closeMap();

private:
    Ui::PlayStarWarsClass ui;
    CharacterSelection* mCharacterSelectScreen;
    Map* mMap;
};
