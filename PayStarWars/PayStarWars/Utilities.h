#pragma once

#include "ui_CharacterSelectionCloneSoldierSelection.h"


class ICharacterInformationScreen : public QMainWindow
{

public:
    ICharacterInformationScreen() = default;
    virtual ~ICharacterInformationScreen(){};

protected:
    virtual void setCharImage(QString imageDir) = 0;
    virtual void setDescription() = 0;
    virtual void setAttributes(QStringList attributes) = 0;

protected:
    Ui::CharacterSelectionCharacter ui;
};
