#pragma once

#include <QtWidgets/QMainWindow>
#include "..\\..\\Utilities.h"

class CloneHeavyGunner : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneHeavyGunner(QWidget* parent = nullptr);
    ~CloneHeavyGunner();

signals:

public slots:

private:
    void prepAttributes(QStringList& attr) override;

};
