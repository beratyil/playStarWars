#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PayStarWars.h"

class PayStarWars : public QMainWindow
{
    Q_OBJECT

public:
    PayStarWars(QWidget *parent = nullptr);
    ~PayStarWars();

signals:
    void clicked();

public slots:
    void exit();
    void openNewGame();

private:
    Ui::PayStarWarsClass ui;
};
