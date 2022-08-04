#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CharacterSelectionCloneSoldierSelection.h"
#include "Map.h"
//#include "CharacterSelectScreen.h"

class ICharacterInformationScreen : public QMainWindow
{
    Q_OBJECT


public:
    ICharacterInformationScreen(QWidget* parent);
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
    void closeMapSender();
    void openMapSender();
    void mapObjectSender(Map* map);
    
public slots:
    void openMap();
    void closeMap();

protected:
    Ui::CharacterSelectionCharacter ui;
    Map* mMap;
};
