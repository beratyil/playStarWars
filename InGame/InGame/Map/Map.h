#pragma once

#include <QtWidgets/QMainWindow>
#include <qfile>
#include <qtextstream.h>
#include <InGame.h>
#include <qsqldatabase.h>
#include <InGameUtilities.h>
#include "ui_Map.h"
#include "Soldier.h"
#include "Soldier/CloneSoldier.h"
#include "Soldier/DroidSoldier.h"
#include "PayStarWars/Utilities.h"

class Map : public QMainWindow
{
	Q_OBJECT

public:
	Map(void* collection, QWidget* parent = nullptr);
	~Map();


signals:
	void returnMainMenu();
	
public slots:
	void moveForward();
	void enterFight();
	void saveProgress();

private:
	/*
	* Might be unncessary
	*/
	void setCurrentPlanet(qint16 planet);

	QPushButton* getCurrentPlanetButton();

	void createEnemyDatabase();

	Ui::Map ui;
	qint16 mCurrentPlanet;
	InGame* mCurrentGame;
	QVector<EnemyDatabase> mEnemies;
	
	Collection* mCollection;
	Soldier* mSoldier;

	QString mDroidEnemies = "..\\..\\Database\\DroidEnemies.txt";
};
