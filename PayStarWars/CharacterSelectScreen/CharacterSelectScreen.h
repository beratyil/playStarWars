#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include "ui_CharacterSelectScreen.h"
#include "Characters/Clone/CloneParatrooper.h"
#include "Characters/Clone/CloneHeavyGunner.h"
#include "Characters/Clone/CloneSharpShooter.h"

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
