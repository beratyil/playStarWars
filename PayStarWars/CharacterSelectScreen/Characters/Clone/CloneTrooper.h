#pragma once

#include <QtWidgets/QMainWindow>
#include "..\\..\\Utilities.h"

class CloneTrooper : public ICharacterInformationScreen
{
    Q_OBJECT

public:
    CloneTrooper(QWidget* parent = nullptr);
    ~CloneTrooper();

signals:

public slots:

private:
    void prepAttributes(QStringList& attr) override;

};
