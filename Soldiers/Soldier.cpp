#include "Soldier.h"

typedef Soldier::SoldierType SoldierType;
typedef Soldier::Type Type;

Soldier::Soldier(QString charName, qint16 level)
    : mLifeForm{}
    , mSoldierType{}
    , mCharName{}
    , mLevel{ level }
{
    if (charName.isEmpty()) {
        mCharName = "";
    }
    else {
        mCharName = charName;
    }
}

QString Soldier::getName()
{
    return mCharName;
}

void Soldier::setType(Type type)
{
    mType = type;
}

Soldier::Type Soldier::getType() const
{
    return mType;
}

QString Soldier::getLifeForm() const {
    return mLifeForm;
}

void Soldier::setLifeForm(QString lifeForm) {
    mLifeForm = lifeForm;
}

SoldierType Soldier::getSoldierType() const {
    return mSoldierType;
}

bool Soldier::setSoldierType(SoldierType soldierType)
{
    bool isSet = false;

    switch (mType) {
        case(Type::Clone): {
            if (qint16(soldierType) < 300 && qint16(soldierType) >= 200) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        case(Type::Droid): {
            if (qint16(soldierType) < 200 && qint16(soldierType) >= 0) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        case(Type::Jedi): {
            if (qint16(soldierType) < 400 && qint16(soldierType) >= 300) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        case(Type::Sith): {
            if (qint16(soldierType) >= 400) {
                mSoldierType = soldierType;
                isSet = true;
            }
            break;
        }
        default:
            isSet = false;
    }

    return isSet;
}

QString Soldier::getSoldierTypeStr() const
{
    QString soldierTypeStr = "";
    switch (mSoldierType)
    {
        case(SoldierType::Admiral): {
            soldierTypeStr = "Admiral";
            break;
        }
        case(SoldierType::BattleDroid): {
            soldierTypeStr = "Battle Droid";
            break;
        }
        case(SoldierType::B2): {
            soldierTypeStr = "B2";
            break;
        }
        case(SoldierType::Commando): {
            soldierTypeStr = "Commando";
            break;
        }
        case(SoldierType::Droideka): {
            soldierTypeStr = "Droideka";
            break;
        }
        case(SoldierType::Grevious_Guard): {
            soldierTypeStr = "Grevious Guard";
            break;
        }
        case(SoldierType::IG_11): {
            soldierTypeStr = "IG-11";
            break;
        }
        case(SoldierType::Assault): {
            soldierTypeStr = "Assault";
            break;
        }
        case(SoldierType::Heavy_Assault): {
            soldierTypeStr = "Heavy Assault";
            break;
        }
        case(SoldierType::Sniper): {
            soldierTypeStr = "Sniper";
            break;
        }
        case(SoldierType::Commander): {
            soldierTypeStr = "Commander";
            break;
        }
        case(SoldierType::Jedi_Padawan): {
            soldierTypeStr = "Jedi Padawan";
            break;
        }
        case(SoldierType::Jedi_Knight): {
            soldierTypeStr = "Jedi Knight";
            break;
        }
        case(SoldierType::Jedi_Master): {
            soldierTypeStr = "Jedi Master";
            break;
        }
        case(SoldierType::Sith_Apprentice): {
            soldierTypeStr = "Sith Apprentice";
            break;
        }
        case(SoldierType::Sith_Master): {
            soldierTypeStr = "Sith Master";
            break;
        }
        default:
            soldierTypeStr = "Uninitalized";
            break;
    }

    return soldierTypeStr;
}

qint16 Soldier::getLevel2() const
{
    return mLevel;
}


