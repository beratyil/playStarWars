#pragma once

#include <QtWidgets/QMainWindow>
#include "Utilities.h"
#include "Soldier\CloneSoldier.h"

class CloneSharpShooter : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneSharpShooter(void* collection, QWidget* parent = nullptr);
    ~CloneSharpShooter();

signals:

public slots:

private:
    void prepAttributes(QStringList& attr) override;
    void setSoldierAttributes() override;

};
