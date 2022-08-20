#include "InGame.h"

InGame::InGame(QString enemyImage, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InGameClass())
{
    ui->setupUi(this);

    QImage imageEnemy(enemyImage);
    QImage imageEnemyMirrored = imageEnemy.mirrored(true, false);

    QPixmap enemyImagePixmap = QPixmap::fromImage(imageEnemyMirrored);

    const int w = ui->enemy->width();
    const int h = ui->enemy->height();

    ui->enemy->setPixmap(enemyImagePixmap.scaled(w, h, Qt::KeepAspectRatio));
    //ui->enemy->setPixmap(enemyImagePixmap);
}

InGame::~InGame()
{
    delete ui;
}
