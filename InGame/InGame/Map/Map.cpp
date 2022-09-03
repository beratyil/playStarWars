#include "Map.h"

Map::Map(QWidget* parent)
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
}

Map::~Map()
{
}

void Map::enterFight()
{
	/* Learn planet number */

	/* According to planet number, call necessary enemy from enemy database */
	EnemyDatabase currentEnemy = mEnemies[mCurrentPlanet - 1];

	mCurrentGame = new InGame(currentEnemy);

	/* Call InGame constructor with necessary information */

	mCurrentGame->show();

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
		QString isMirrored = column.at(3);

		bool mirroringNeeded = true;

		if (isMirrored.startsWith("No"))
		{
			mirroringNeeded = false;
		}

		EnemyDatabase newEnemy(index.toShort(), image, soldierType, mirroringNeeded);

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
