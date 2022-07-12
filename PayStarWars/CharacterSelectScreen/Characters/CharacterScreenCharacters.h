#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include "ui_CharacterSelectionCloneSoldierSelection.h"

class ICharacterInformationScreen
{
    Q_OBJECT

public:
    ICharacterInformationScreen() = default;
    virtual ~ICharacterInformationScreen() = 0;

protected:
    virtual void setCharImage(QString imageDir) = 0;
    virtual void setDescription(QString description) = 0;
    virtual void setAttributes(QStringList attributes) = 0;


signals:

public slots:

protected:
    Ui::CharacterSelectionCharacter ui;
};
