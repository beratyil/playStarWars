#include "Soldier.h"

typedef Soldier::SoldierType SoldierType;
typedef Soldier::Type Type;

Soldier::Soldier()
{
    
}

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

void Soldier::setName(QString name)
{
    if (mCharName.isEmpty()) {
        mCharName = name;
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

QString Soldier::getTypeStr() const
{
    QString returnTypeStr = "";
    switch (mType)
    {
    case Soldier::Type::UNINITIALIZED:
        break;
    case Soldier::Type::Droid:
        returnTypeStr = "Droid";
        break;
    case Soldier::Type::Clone:
        returnTypeStr = "Clone";
        break;
    case Soldier::Type::Jedi:
        returnTypeStr = "Jedi";
        break;
    case Soldier::Type::Sith:
        returnTypeStr = "Sith";
        break;
    default:
        break;
    }

    return returnTypeStr;
}

qint16 Soldier::getTypeIndex(Type type)
{
    qint16 index = 0;

    index = static_cast<qint16>(type);

    return index;
}

Type Soldier::getTypeFromIndex(qint16 index)
{
    Type type = Type::UNINITIALIZED;

    type = static_cast<Type>(index);
    
    return type;
}

qint16 Soldier::getSoldierTypeIndex(SoldierType type)
{
    qint16 index = 0;

    index = static_cast<qint16>(type);

    return index;
}

SoldierType Soldier::getSoldierTypeFromIndex(qint16 index)
{
    SoldierType type = SoldierType::UNINITIALIZED;

    type = static_cast<SoldierType>(index);

    return type;
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
        case(SoldierType::Officer): {
            soldierTypeStr = "Officer";
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
