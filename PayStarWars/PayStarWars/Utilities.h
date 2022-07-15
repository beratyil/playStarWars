#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CharacterSelectionCloneSoldierSelection.h"

class ICharacterInformationScreen : public QMainWindow
{
    Q_OBJECT


public:
    ICharacterInformationScreen(QWidget* parent);
    ICharacterInformationScreen() = default;
    virtual ~ICharacterInformationScreen(){};

    void closed();

protected:
    void prepInfoScreen(QString imageDir, QString desc, QStringList& attr);
    
    virtual void setCharImage(QString imageDir);
    virtual void setDescription(QString description);
    virtual void setAttributes(QStringList& attributes);

    virtual void prepAttributes(QStringList& attr) = 0;

signals:
    void goBack();
    
public slots:
    virtual void test() {};

protected:
    Ui::CharacterSelectionCharacter ui;
};
