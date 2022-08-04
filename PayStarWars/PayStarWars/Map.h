#pragma once

#include "ui_Map.h"
#include <QtWidgets/QMainWindow>

class Map : public QMainWindow
{
	Q_OBJECT

public:
	Map(QWidget* parent = nullptr);
	~Map();

	

private:
	Ui::Map ui;

};
