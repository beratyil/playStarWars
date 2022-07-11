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
    void returnMainMenuSignal();

public slots:
    void returnMainMenuSlot();

private:
    Ui::CharacterSelection ui;
};
