#pragma once

#include <QtWidgets/QMainWindow>
#include <Utilities.h>
#include "Soldier\CloneSoldier.h"

class CloneHeavyGunner : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneHeavyGunner(void* collection, QWidget* parent = nullptr);
    ~CloneHeavyGunner();

signals:

public slots:

private:
    void prepAttributes(QStringList& attr) override;
    void setSoldierAttributes() override;

};
