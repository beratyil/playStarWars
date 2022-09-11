#pragma once

#include "soldier_global.h"
#include "qstring.h"

class SOLDIER_EXPORT JediSoldier
{
public:
    JediSoldier();

private:
    qint16 health;
    qint16 armor;

    QString lifeForm;
    QString soldierType;
};
