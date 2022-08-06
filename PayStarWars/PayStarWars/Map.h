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

private:
	Ui::Map ui;

};
