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
    void setCharImage(QString imageDir);
    void setDescription(QString description);
    void setAttributes(QStringList attributes);
};
