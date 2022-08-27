#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Map.h"
#include "..\\InGame.h"
#include <qsqldatabase.h>
#include "..\\InGameUtilities.h"
#include <qfile>
#include <qtextstream.h>

class Map : public QMainWindow
{
	Q_OBJECT

public:
	Map(QWidget* parent = nullptr);
	~Map();


signals:
	void returnMainMenu();
	
public slots:
	void moveForward();
	void enterFight();

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

	QString mDroidEnemies = "..\\..\\Database\\DroidEnemies.txt";
};
