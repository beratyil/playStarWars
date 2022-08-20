#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Map.h"
#include "..\\InGame.h"
#include <qsqldatabase.h>

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


	Ui::Map ui;
	qint16 currentPlanet;
	InGame* m_currentGame;


	QMap<qint16, QString> mEnemyMap = {
		{1, ":\\Droid_1Level\\Resources\\Soldiers\\Droids\\ClassicBattleDroid.jpg"},
		{2, ":\\Droid_Level1\\Resources\\Soldiers\\Droids\\Admiral.png"},
		{3, ":\\Droid_Level1\\Resources\\Soldiers\\Droids\\B2.jpg"},
		{4, ":\\Droid_Level1\\Resources\\Soldiers\\Droids\\Droideka.jpg"},
		{5, ":\\Droid_Level1\\Resources\\Soldiers\\Droids\\Commando.jpg"},
		{6, ":\\Droid_Level1\\Resources\\Soldiers\\Droids\\Grevious Guard.jpg"},
		{7, ":\\Droid_Level1\\Resources\\Soldiers\\Droids\\IG-11.png"},
		{8, ":\\Droid_Level1\\Resources\\Soldiers\\Droids\\BattleDroid.jpg"},
	};
};
