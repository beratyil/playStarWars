#pragma once

#include <QtWidgets/QMainWindow>
#include <Utilities.h>
#include "Soldier\CloneSoldier.h"

class CloneOfficer : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneOfficer(Collection* collection, QWidget* parent = nullptr);
    ~CloneOfficer();

signals:

public slots:

private slots:

private:
    void setSoldierAttributes() override;
    void prepAttributes(QStringList& attr) override;
};
