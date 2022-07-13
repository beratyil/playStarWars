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
    void setCharImage(QString imageDir);
    void setDescription();
    void setAttributes(QStringList attributes);
    
    QStringList prepAttributes();
};
