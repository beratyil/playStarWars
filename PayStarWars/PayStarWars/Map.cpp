#include "Map.h"

Map::Map(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QPixmap pixmapMap("..\\Resources\\Map\\SpaceMap.jpg");
	ui.backGround->setPixmap(pixmapMap);

	connect(ui.mainMenuButton, &QPushButton::clicked, this, &Map::returnMainMenu);
}

Map::~Map()
{
}