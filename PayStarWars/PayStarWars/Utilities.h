#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CharacterSelectionCloneSoldierSelection.h"
#include "Soldier.h"

/*
* Hide elements going through classes
*/
class Collection
{
public:
    Collection(Soldier* soldier);

    Soldier** getSoldier();

    void setName(QString name);
    QString* getName();

private:
    Soldier** mSoldier;
    QString* mCharName;

};

class ICharacterInformationScreen : public QMainWindow
{
    Q_OBJECT

public:
    ICharacterInformationScreen(Collection* collection, QWidget* parent = nullptr);
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
    void enterCharacterNameScreen();
    void continueMap();
    
public slots:
    virtual void setSoldierAttributes() = 0;

protected:
    Ui::CharacterSelectionCharacter ui;
    Soldier** mSoldier;
    Collection* mCollection;


private:
};


