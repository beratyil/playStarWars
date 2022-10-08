#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include "ui_CharacterNameScreen.h"
#include "Characters/Clone/CloneOfficer.h"
#include "Characters/Clone/CloneHeavyGunner.h"
#include "Characters/Clone/CloneSharpShooter.h"
#include "Characters/Clone/CloneTrooper.h"
#include "Utilities.h"

class CharacterName : public QMainWindow
{
    Q_OBJECT

public:
    CharacterName(Collection* collection, QWidget* parent = nullptr);
    ~CharacterName();

    void exit();

signals:
    void returnSelection();
    void continueMap();
    void createSoldier();

public slots:
    void setName();

private:
    Ui::CharacterNameScreen ui;
    Collection* mCollection;
};
