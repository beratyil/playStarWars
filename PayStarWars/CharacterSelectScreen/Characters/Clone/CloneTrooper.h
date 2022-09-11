#pragma once

#include <QtWidgets/QMainWindow>
#include "Utilities.h"
#include "Soldier\CloneSoldier.h"

class CloneTrooper : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneTrooper(void* collection, QWidget* parent = nullptr);
    ~CloneTrooper();

signals:

public slots:

private:
    void prepAttributes(QStringList& attr) override;
    void setSoldierAttributes() override;

};
