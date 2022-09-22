#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include "ui_CharacterSelectScreen.h"
#include "Characters/Clone/CloneParatrooper.h"
#include "Characters/Clone/CloneHeavyGunner.h"
#include "Characters/Clone/CloneSharpShooter.h"
#include "Characters/Clone/CloneTrooper.h"

class CharacterSelection : public QMainWindow
{
    Q_OBJECT

public:
    CharacterSelection(Collection* collection, QWidget* parent = nullptr);
    ~CharacterSelection();

    void exit();

signals:
    void returnMainMenu();
    void openMapSender();

public slots:
    void openCharacterInformationScreen();
    void closeCharacterInformationScreen();

private:
    Ui::CharacterSelection ui;
    ICharacterInformationScreen* mCharInfoScreen;
    Collection* mCollection;
};
