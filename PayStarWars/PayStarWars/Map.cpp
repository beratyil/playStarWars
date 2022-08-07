#include "Map.h"

Map::Map(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QPixmap pixmapMap(":\PlayStarWars\\Resources\\Map\\SpaceMap.png");
	ui.backGround->setPixmap(pixmapMap);

	connect(ui.mainMenuButton, &QPushButton::clicked, this, &Map::returnMainMenu);

	connect(ui.buttonForward, &QPushButton::clicked, this, &Map::moveForward);

	currentPlanet = 1;
}

Map::~Map()
{
}

void Map::setCurrentPlanet(qint16 planet)
{
	currentPlanet = planet;
}

QPushButton* Map::getCurrentPlanetButton()
{
	QPushButton* tempPlanet;

	switch (currentPlanet)
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
	case 9:
		tempPlanet = ui.pushButton_9;
	default:
		tempPlanet = ui.pushButton_1;
	}

	return tempPlanet;
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
		"background-color: black;\n"
		"	opacity: 0.2;\n"
		"}"));

	currentPlanet++;
	
	currentPlanetEdit = getCurrentPlanetButton();

	/* Color the Current Planet */
	currentPlanetEdit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
		"	border-style: solid;\n"
		"	border-width:2px;\n"
		"	border-color: red;\n"
		"	border-radius: 20px;\n"
		"background-color: black;\n"
		"	opacity: 0.2;\n"
		"}"));
}
