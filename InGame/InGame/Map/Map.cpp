#include "Map.h"

Map::Map(Collection* collection, QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QPixmap pixmapMap(":/Map/Resources/Map/SpaceMap2.png");
	ui.backGround->setPixmap(pixmapMap);

	connect(ui.mainMenuButton, &QPushButton::clicked, this, &Map::returnMainMenu);

	connect(ui.buttonForward, &QPushButton::clicked, this, &Map::moveForward);

	mCurrentPlanet = 0;

	moveForward();

	connect(ui.pushButton_1, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_5, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_6, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_7, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_8, &QPushButton::clicked, this, &Map::enterFight);
	connect(ui.pushButton_9, &QPushButton::clicked, this, &Map::enterFight);

	createEnemyDatabase();

	mCollection = static_cast<Collection*>(collection);
	mSoldier = *(mCollection->getSoldier());
	
	QString* charName = mCollection->getName();
	mSoldier->setName(*charName);
	
	delete charName;
	charName = nullptr;

	saveProgress();
}

Map::~Map()
{
}

void Map::enterFight()
{
	/* Default Hero */

	/* According to planet number, call necessary enemy from enemy database */
	EnemyDatabase currentEnemy = mEnemies[mCurrentPlanet - 1];

	mCurrentGame = new InGame(mCollection, currentEnemy);

	/* Call InGame constructor with necessary information */

	mCurrentGame->show();

}

void Map::saveProgress()
{
	QDir dir("..\\..\\Database\\heroProgress.txt");
	QString currerntPath = QDir::currentPath();

	QString absolutePath = dir.absolutePath();
	
	absolutePath = absolutePath.replace("/", "\\\\");

	QFile file(absolutePath);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

		Health* health = dynamic_cast<Health*>(mSoldier);
		
		qint16 type = Soldier::getTypeIndex(mSoldier->getType());

		qint16 weaponIndex = DroidWeapon::getWeaponIndex( DroidWeapon::Weapon::UNINITIALIZED );

		qint16 rangeIndex = DroidWeapon::getRangeIndex(DroidWeapon::Range::UNINITIALIZED);

		QStringList commonSkillList;

		QStringList specialSkillList;

		switch (type) {
			case 0:
			{
				DroidAttack* soldierAttack = dynamic_cast<DroidAttack*>(mSoldier);

				weaponIndex = DroidWeapon::getWeaponIndex( soldierAttack->getWeapon().getWeapon() );

				rangeIndex = DroidWeapon::getRangeIndex(soldierAttack->getWeapon().getRange() );

				QVector < DroidCommonSkill::CommonSkill > commonSkills = soldierAttack->getCommonSkills();

				for (auto it = commonSkills.begin(); it != commonSkills.end(); it++) {
					
					qint16 index = DroidCommonSkill::getCommonSkillIndex(*it);

					commonSkillList.append(QString::number(index));
				}
				
				QVector<DroidSpecialSkill::Equipment> specialSkills = soldierAttack->getSpecialSkills();

				for (auto it = specialSkills.begin(); it != specialSkills.end(); it++) {

					qint16 index = DroidSpecialSkill::getSpecialSkillIndex(*it);

					specialSkillList.append(QString::number(index));
				}
			}
			case 1:
			{
				CloneAttack* soldierAttack = dynamic_cast<CloneAttack*>(mSoldier);

				weaponIndex = CloneWeapon::getWeaponIndex( soldierAttack->getWeapon().getWeapon() );
				
				rangeIndex = CloneWeapon::getRangeIndex(soldierAttack->getWeapon().getRange());

				QVector < CloneCommonSkill::CommonSkill > commonSkills = soldierAttack->getCommonSkills();

				for (auto it = commonSkills.begin(); it != commonSkills.end(); it++) {

					qint16 index = DroidCommonSkill::getCommonSkillIndex(*it);

					commonSkillList.append(QString::number(index));
				}

				QVector<CloneSpecialSkill::Equipment> specialSkills = soldierAttack->getSpecialSkills();

				for (auto it = specialSkills.begin(); it != specialSkills.end(); it++) {

					qint16 index = CloneSpecialSkill::getSpecialSkillIndex(*it);

					specialSkillList.append(QString::number(index));
				}
			}
			case 2:
			{
				// TODO: Create JediWeapon
				//JediWeapon* weapon;
			}
			case 3:
			{
				//DroidWeapon* weapon;
			}
			default:
				CloneAttack* soldierAttack = dynamic_cast<CloneAttack*>(mSoldier);
				typedef DroidAttack attackType;
		}

		QString nameLine = mSoldier->getName() + "\n";

		QString lifeFormLine = mSoldier->getLifeForm() + "\n";

		QString typeLine = QString::number(type) + "\n";

		QString soldierTypeLine = QString::number( Soldier::getSoldierTypeIndex( mSoldier->getSoldierType() ) ) + "\n";

		QString levelLine = QString::number(health->getLevel()) + "\n";

		QString weaponLine = QString::number(weaponIndex) + "," + QString::number(rangeIndex) + "\n";
		
		QString commonSkillLine = commonSkillList.join(",") + "\n";
		
		QString specialSkillLine = specialSkillList.join(",") + "\n";

		QString currentHealthLine = QString::number(health->getCurrentHealth()) + "\n";

		QString maxHealthLine = QString::number(health->getMaxHealth()) + "\n";

		QString currentArmorLine = QString::number(health->getCurrentArmor()) + "\n";
		
		QString maxArmorLine = QString::number(health->getMaxArmor()) + "\n";


		file.write(nameLine.toLatin1());
		file.write(lifeFormLine.toLatin1());
		file.write(typeLine.toLatin1());
		file.write(soldierTypeLine.toLatin1());
		file.write(levelLine.toLatin1());
		file.write(weaponLine.toLatin1());
		file.write(commonSkillLine.toLatin1());
		file.write(specialSkillLine.toLatin1());
		file.write(currentHealthLine.toLatin1());
		file.write(maxHealthLine.toLatin1());
		file.write(currentArmorLine.toLatin1());
		file.write(maxArmorLine.toLatin1());

		file.close();
		
	}
	else {
		qDebug("Error at saving game!");
	}
}

void Map::loadGame()
{
	QDir dir("..\\..\\Database\\heroProgress.txt");

	QString absolutePath = dir.absolutePath();

	absolutePath = absolutePath.replace("/", "\\\\");

	QFile file(absolutePath);

	// TODO: file is not created
	if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {

		QString nameLine = file.readLine();
		QString lifeFormLine = file.readLine();
		QString typeLine = file.readLine();
		QString soldierTypeLine = file.readLine();
		QString levelLine = file.readLine();
		QString weaponLine = file.readLine();
		QString rangeLine = file.readLine();
		QString commonSkillLine = file.readLine();
		QString specialSkillLine = file.readLine();
		QString currentHealthLine = file.readLine();
		QString maxHealthLine = file.readLine();
		QString currentArmorLine = file.readLine();
		QString maxArmorLine = file.readLine();

		file.close();

		qint16 typeIndex = typeLine.toShort();
		qint16 soldierTypeIndex = soldierTypeLine.toShort();
		qint16 levelIndex = levelLine.toShort();

		qint16 weaponIndex = weaponLine.split(",")[0].toShort();
		qint16 rangeIndex = weaponLine.split(",")[1].toShort();

		Soldier* newSoldier = nullptr;

		Soldier::SoldierType soldierType = Soldier::getSoldierTypeFromIndex(typeIndex);

		// TODO: create Clone and Jedi Objects Here
		switch (typeIndex)
		{
			default:
				break;
			case 1: {

				DroidWeapon::Weapon weapon = DroidWeapon::getWeaponFromIndex(weaponIndex);
				DroidWeapon::Range range = DroidWeapon::getRangeFromIndex(rangeIndex);

				newSoldier = new Droid(nameLine, lifeFormLine, soldierType, levelIndex, weapon, range);
				break;
			}
			case 2:
			{
				DroidWeapon::Weapon weapon = DroidWeapon::getWeaponFromIndex(weaponIndex);
				DroidWeapon::Range range = DroidWeapon::getRangeFromIndex(rangeIndex);

				newSoldier = new Droid(nameLine, lifeFormLine, soldierType, levelIndex, weapon, range);
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				break;
			}
		}
	}
	else {

	}
}

void Map::setCurrentPlanet(qint16 planet)
{
	mCurrentPlanet = planet;
}

QPushButton* Map::getCurrentPlanetButton()
{
	QPushButton* tempPlanet;

	qint16 remainder = mCurrentPlanet % 9;

	switch (remainder)
	{
	case 1:
		tempPlanet = ui.pushButton_1;
		break;
	case 2:
		tempPlanet = ui.pushButton_2;
		break;
	case 3:
		tempPlanet = ui.pushButton_3;
		break;
	case 4:
		tempPlanet = ui.pushButton_4;
		break;
	case 5:
		tempPlanet = ui.pushButton_5;
		break;
	case 6:
		tempPlanet = ui.pushButton_6;
		break;
	case 7:
		tempPlanet = ui.pushButton_7;
		break;
	case 8:
		tempPlanet = ui.pushButton_8;
		break;
	case 0:
		tempPlanet = ui.pushButton_9;
		break;
	default:
		tempPlanet = ui.pushButton_1;
		break;
	}

	return tempPlanet;
}

void Map::createEnemyDatabase()
{
	QString databaseFileLine = "";

	QFile file(mDroidEnemies);

	if (file.open(QIODevice::ReadOnly))
	{
		// thrown an exception
	}

	while (!file.atEnd())
	{
		QByteArray line = file.readLine();

		QList<QByteArray> column = line.split(',');

		QString index = column.at(0);
		QString image = column.at(1);
		QString soldierType = column.at(2);
		QString level = column.at(3);
		QString isMirrored = column.at(4);

		bool mirroringNeeded = true;

		if (isMirrored.startsWith("No"))
		{
			mirroringNeeded = false;
		}

		EnemyDatabase newEnemy((unsigned)index.toShort(), image, soldierType, (signed)level.toShort(), mirroringNeeded);

		mEnemies.append(newEnemy);
	}
}

void Map::moveForward()
{
	QPushButton* currentPlanetEdit = getCurrentPlanetButton();

	/* Restore the Planet */
	currentPlanetEdit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
		"	border-style: solid;\n"
		"	border-width:2px;\n"
		"	border-color: red;\n"
		"	border-radius: 20px;\n"
		"}"));

	mCurrentPlanet++;
	
	currentPlanetEdit = getCurrentPlanetButton();

	/* Color the Current Planet */
	currentPlanetEdit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
		"	border-style: solid;\n"
		"	border-width:7px;\n"
		"	border-color: red;\n"
		"	border-radius: 20px;\n"
		"	opacity: 0.2;\n"
		"}"));
}
