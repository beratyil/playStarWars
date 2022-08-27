#include "InGame.h"

InGame::InGame(EnemyDatabase currentEnemy, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InGameClass())
{
    ui->setupUi(this);

    QString enemyImage = currentEnemy.getImageLocation();

    QImage imageEnemy(enemyImage);
    QImage imageEnemyMirrored = imageEnemy.mirrored(true, false);

    QPixmap enemyImagePixmap = QPixmap::fromImage(imageEnemyMirrored);

    const int w = ui->enemy->width();
    const int h = ui->enemy->height();

    ui->enemy->setPixmap(enemyImagePixmap.scaled(w, h, Qt::KeepAspectRatio));

    QImage imageHero("C:\\Users\\aby_6\\Documents\\Programming\\QT\\StarWarsApp\\InGame\\InGame\\Resources\\Soldiers\\Clones\\CloneCommando.jpg");
    QPixmap heroImagePixmap = QPixmap::fromImage(imageHero);
    ui->hero->setPixmap(heroImagePixmap);
}

InGame::~InGame()
{
    delete ui;
}
