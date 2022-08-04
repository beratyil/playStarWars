#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PayStarWars.h"
#include "CharacterSelectScreen.h"

class PayStarWars : public QMainWindow
{
    Q_OBJECT

public:
    PayStarWars(QWidget *parent = nullptr);
    ~PayStarWars();

signals:
    void clicked();

public slots:
    void exit();
    void openNewGame();
    void returnMainMenu();
    
    /*
    * Hold Character Information Screen Object
    * M�ght be uncessary
    */
    void charInfoScreenReceiver(ICharacterInformationScreen* charInfoScreen);
    
    /*
    Kill all the screens
    1.Kill Character Information Screen
    2.Kill Character Selection Screen
    */
    void killCharInfoScreen();

private:
    Ui::PayStarWarsClass ui;
    CharacterSelection* mCharacterSelectScreen;
    ICharacterInformationScreen* mCharInfoScreen;
    Map* mMap;
};
