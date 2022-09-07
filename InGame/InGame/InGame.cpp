#include "InGame.h"
#include "Soldier\CloneSoldier.h"
#include "Soldier.h"

using SoldierSpace::CloneWeapon;

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

    exampleInGameScreen();

}

void InGame::exampleInGameScreen()
{
    /* @note: test hero image */
    QImage imageHero("C:\\Users\\aby_6\\Documents\\Programming\\QT\\StarWarsApp\\InGame\\InGame\\Resources\\Soldiers\\Clones\\CloneCommando.jpg");
    QPixmap heroImagePixmap = QPixmap::fromImage(imageHero);
    ui->hero->setPixmap(heroImagePixmap);

    Soldier* hero = new Clone(10, 10, "Human", Soldier::SoldierType::Assault, CloneWeapon::Weapon::DC_15A_CARBINE);

    CloneAttack* attackInterface = dynamic_cast<CloneAttack*>(hero);
    attackInterface->addSkill(CloneAttack::skillType::commonSkill, 0);
    attackInterface->addSkill(CloneAttack::skillType::commonSkill, 1);
    attackInterface->addSkill(CloneAttack::skillType::commonSkill, 2);

    attackInterface->addSkill(CloneAttack::skillType::specialSkill, 0);
    attackInterface->addSkill(CloneAttack::skillType::specialSkill, 1);
    attackInterface->addSkill(CloneAttack::skillType::specialSkill, 2);

    QStringList commonSkills = attackInterface->getCommonSkillsString();
    QStringList specialSkills = attackInterface->getSpecialSkillsString();

    ui->comSkill_1->setText(commonSkills[0]);
    ui->comSkill_2->setText(commonSkills[1]);
    ui->comSkill_3->setText(commonSkills[2]);

    ui->speSkill_1->setText(specialSkills[0]);
    ui->speSkill_2->setText(specialSkills[1]);
    ui->speSkill_3->setText(specialSkills[2]);
}

InGame::~InGame()
{
    delete ui;
}
