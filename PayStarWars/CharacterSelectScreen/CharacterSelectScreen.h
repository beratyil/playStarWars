#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include "ui_CharacterSelectScreen.h"
#include "..\\..\\PayStarWars\PayStarWars\Utilities.h"
#include "Characters/Clone/CloneParatrooper.h"
#include "Characters/Clone/CloneHeavyGunner.h"  

class CharacterSelection : public QMainWindow
{
    Q_OBJECT

public:
    CharacterSelection(QWidget* parent = nullptr);
    ~CharacterSelection();

    void exit();

signals:
    void clicked();
    void returnMainMenu();

public slots:
    void openCharacterInformationScreen();
    void closeCharacterInformationScreen();

private:
    Ui::CharacterSelection ui;
    ICharacterInformationScreen* mCharInfoScreen;
};
