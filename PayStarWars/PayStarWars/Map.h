#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Map.h"

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

private:
	/*
	* Might be unncessary
	*/
	void setCurrentPlanet(qint16 planet);

	QPushButton* getCurrentPlanetButton();


	Ui::Map ui;
	qint16 currentPlanet;

};
