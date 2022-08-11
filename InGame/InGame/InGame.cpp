#include "InGame.h"

InGame::InGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InGameClass())
{
    ui->setupUi(this);
}

InGame::~InGame()
{
    delete ui;
}
