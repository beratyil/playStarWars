#include "InGame.h"
#include "Soldier\CloneSoldier.h"
#include "Soldier.h"

using SoldierSpace::CloneWeapon;

InGame::InGame(void* collection, EnemyDatabase currentEnemy, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InGameClass())
{
    ui->setupUi(this);

    //Q_INIT_RESOURCE(InGame);
    bool isRegistered = QResource::registerResource("InGame.qrc");

    QString enemyImage = currentEnemy.getImageLocation();

    QImage imageEnemy(enemyImage);
    QImage imageEnemyMirrored = imageEnemy.mirrored(true, false);

    QPixmap enemyImagePixmap = QPixmap::fromImage(imageEnemyMirrored);

    const int w = ui->enemy->width();
    const int h = ui->enemy->height();

    ui->enemy->setPixmap(enemyImagePixmap.scaled(w, h, Qt::KeepAspectRatio));

    exampleInGameScreen();

    mCollection = static_cast<Collection*>(collection);
    mSoldier = mCollection->getSoldier();
}

void InGame::exampleInGameScreen()
{
    /* @note: test hero image */
    QString image = ":/Droid_1Level/Resources/Soldiers/Droids/Droideka.png";

    QImage imageHero(image);
    /*QPixmap heroImagePixmap = QPixmap::fromImage(imageHero);
    ui->hero->setPixmap(heroImagePixmap);*/

    QImage imageEnemy(imageHero);
    QImage imageEnemyMirrored = imageEnemy.mirrored(true, false);

    QPixmap enemyImagePixmap = QPixmap::fromImage(imageEnemyMirrored);

    const int w = ui->enemy->width();
    const int h = ui->enemy->height();

    ui->hero->setPixmap(enemyImagePixmap.scaled(w, h, Qt::KeepAspectRatio));

    Soldier* hero = new Clone("Rex", "Human", Soldier::SoldierType::Commander, 10, CloneWeapon::Weapon::DC_15A_CARBINE);

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

void InGame::gameTurn()
{
    QObject* sender = QObject::sender();

    /* @note: get name of the object */
    QString objectName = sender->objectName();

    if (objectName == "comSkill_1") {
        //infoScreen = new CloneParatrooper();
    }
    else if (objectName == "comSkill_2") {
        //infoScreen = new CloneHeavyGunner();
    }
    else if (objectName == "comSkill_3") {
        //infoScreen = new CloneSharpShooter();
    }
    else if (objectName == "speSkill_1") {
        //infoScreen = new CloneTrooper();
    }
    else if (objectName == "speSkill_1") {
        //infoScreen = new CloneTrooper();
    }
    else if (objectName == "speSkill_1") {
        //infoScreen = new CloneTrooper();
    }
    else {

    }
}
