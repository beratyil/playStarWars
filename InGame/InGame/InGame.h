#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InGame.h"
#include "InGameUtilities.h"
#include <qresource.h>
#include "PayStarWars/Utilities.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InGameClass; };
QT_END_NAMESPACE

class InGame : public QMainWindow
{
    Q_OBJECT

public:
    //InGame(Soldier* hero, EnemyDatabase currentEnemy, QWidget* parent = nullptr);
    InGame(void* collection, EnemyDatabase currentEnemy, QWidget* parent = nullptr);
    ~InGame();

public slots:
    void gameTurn();

private:
    Ui::InGameClass *ui;

    /* @note: call for testing Game Screen Features */
    void InGame::exampleInGameScreen();

    Soldier* mSoldier;
    Collection* mCollection;

};
