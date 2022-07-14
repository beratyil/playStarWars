#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CharacterSelectionCloneSoldierSelection.h"

class ICharacterInformationScreen : public QMainWindow
{

public:
    ICharacterInformationScreen(QWidget* parent);
    ICharacterInformationScreen() = default;
    virtual ~ICharacterInformationScreen(){};

protected:
    virtual void setCharImage(QString imageDir);
    virtual void setDescription(QString description);
    virtual void setAttributes(QStringList attributes);

    virtual QStringList prepAttributes() = 0;


protected:
    Ui::CharacterSelectionCharacter ui;
};
