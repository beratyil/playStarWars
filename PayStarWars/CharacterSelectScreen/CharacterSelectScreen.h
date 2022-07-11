#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CharacterSelectScreen.h"

class CharacterSelection : public QMainWindow
{
    Q_OBJECT

public:
    CharacterSelection(QWidget* parent = nullptr);
    ~CharacterSelection();

signals:
    void clicked();

public slots:
    void returnMainMenu();

private:
    Ui::CharacterSelection ui;
};
