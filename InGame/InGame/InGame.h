#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InGame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InGameClass; };
QT_END_NAMESPACE

class InGame : public QMainWindow
{
    Q_OBJECT

public:
    InGame(QString enemyImage, QWidget *parent = nullptr);
    ~InGame();

private:
    Ui::InGameClass *ui;
};
