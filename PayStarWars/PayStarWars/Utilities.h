#pragma once

#include "ui_CharacterSelectionCloneSoldierSelection.h"


class ICharacterInformationScreen
{

public:
    ICharacterInformationScreen() = default;
    virtual ~ICharacterInformationScreen(){};

protected:
    virtual void setCharImage(QString imageDir) = 0;
    virtual void setDescription(QString description) = 0;
    virtual void setAttributes(QStringList attributes) = 0;

protected:
    Ui::CharacterSelectionCharacter ui;
};
