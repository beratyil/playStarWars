#pragma once

#include <QtWidgets/QMainWindow>
#include <Utilities.h>
#include "Soldier\CloneSoldier.h"

class CloneHeavyGunner : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneHeavyGunner(Collection* collection, QWidget* parent = nullptr);
    ~CloneHeavyGunner();

signals:

public slots:
    void setSoldierAttributes() override;

private:
    void prepAttributes(QStringList& attr) override;

};
