#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include "ui_CharacterSelectScreen.h"
#include "..\\..\\PayStarWars\PayStarWars\Utilities.h"
#include "Characters/Clone/CloneParatrooper.h"

class CharacterSelection : public QMainWindow
{
    Q_OBJECT

public:
    CharacterSelection(QWidget* parent = nullptr);
    ~CharacterSelection();

    void exit();

signals:
    void clicked();
    void returnMainMenuSignal();

public slots:
    void returnMainMenuSlot();
    void openCharacterInformationScreen();

private:
    Ui::CharacterSelection ui;
};
