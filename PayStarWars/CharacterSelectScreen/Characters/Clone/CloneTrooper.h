#pragma once

#include <QtWidgets/QMainWindow>
#include "Utilities.h"
#include "Soldier\CloneSoldier.h"

class CloneTrooper : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneTrooper(Collection* collection, QWidget* parent = nullptr);
    ~CloneTrooper();

signals:

public slots:
    void setSoldierAttributes() override;

private:
    void prepAttributes(QStringList& attr) override;

};
