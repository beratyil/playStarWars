#pragma once

#include <QtWidgets/QMainWindow>
#include "Utilities.h"
#include "Soldier\CloneSoldier.h"

class CloneSharpShooter : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneSharpShooter(Collection* collection, QWidget* parent = nullptr);
    ~CloneSharpShooter();

signals:

public slots:
    void setSoldierAttributes() override;

private:
    void prepAttributes(QStringList& attr) override;

};
