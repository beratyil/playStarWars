#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CharacterSelectionCloneSoldierSelection.h"
#include "Soldier.h"

class ICharacterInformationScreen : public QMainWindow
{
    Q_OBJECT


public:
    ICharacterInformationScreen(void* collection, QWidget* parent = nullptr);
    ICharacterInformationScreen() = default;
    virtual ~ICharacterInformationScreen(){};

protected:
    void prepInfoScreen(QString imageDir, QString desc, QStringList& attr);
    
    virtual void setCharImage(QString imageDir);
    virtual void setDescription(QString description);
    virtual void setAttributes(QStringList& attributes);

    virtual void prepAttributes(QStringList& attr) = 0;

signals:
    void goBack();
    void openMapSender();
    
public slots:
    void startGame();

protected:
    Ui::CharacterSelectionCharacter ui;
    Soldier** mSoldier;

    // TODO: delete Soldier Name, add character name selection screen
    QString mSoldierName = "Default";

private:
    virtual void setSoldierAttributes() = 0;
};

/*
* Hide elements going through classes
*/
class Collection
{
public:

    Collection(Soldier* soldier);

    Soldier** getSoldier();

private:
    Soldier** mSoldier;

};
