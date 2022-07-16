#pragma once

#include <QtWidgets/QMainWindow>
#include "..\\..\\Utilities.h"

class CloneSharpShooter : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneSharpShooter(QWidget* parent = nullptr);
    ~CloneSharpShooter();

signals:

public slots:

private:
    void prepAttributes(QStringList& attr) override;

};
