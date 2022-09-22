#pragma once

#include <QtWidgets/QMainWindow>
#include <Utilities.h>
#include "Soldier\CloneSoldier.h"

class CloneParatrooper : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneParatrooper(Collection* collection, QWidget* parent = nullptr);
    ~CloneParatrooper();

signals:

public slots:

private slots:

private:
    void prepAttributes(QStringList& attr) override;
    void setSoldierAttributes() override;
};
