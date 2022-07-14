#pragma once

#include <QtWidgets/QMainWindow>
#include "..\\..\\Utilities.h"

class CloneParatrooper : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneParatrooper(QWidget* parent = nullptr);
    ~CloneParatrooper();

signals:

public slots:

private:
    QStringList prepAttributes() override;
};
