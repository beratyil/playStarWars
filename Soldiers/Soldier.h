#pragma once

#include "soldier_global.h"
#include "qstring.h"
#include "qstringlist.h"

//Soldier Abstract Class
//Used as pointer for every type of Soldier Classes,
//e.x Clone, Droid, Jedi or Sith

class SOLDIER_EXPORT Soldier
{
public:

    enum class Type {
        Uninitalized,
        Droid,
        Clone,
        Jedi,
        Sith
    };

    enum class SoldierType {
        Uninitalized = -1,
        Admiral = 100,
        BattleDroid,
        B2,
        Commando,
        Droideka,
        Grevious_Guard,
        IG_11,
        Assault = 200,
        Heavy_Assault,
        Sniper,
        Commander,
        Jedi_Padawan = 300,
        Jedi_Knight,
        Jedi_Master,
        Sith_Apprentice = 400,
        Sith_Master
    };

    Soldier();

    Soldier(QString charName, qint16 level);

    void setName(QString name);

    QString getName();

    Type getType() const;

    QString getTypeStr() const;

    static qint16 getTypeIndex(Type type);

    static Type getTypeFromIndex(qint16 index);

    static qint16 getSoldierTypeIndex(SoldierType type);

    static SoldierType getSoldierTypeFromIndex(qint16 index);

    qint16 getLevel2() const;

    QString getLifeForm() const;

    void setLifeForm(QString lifeForm);

    SoldierType getSoldierType() const;

    QString getSoldierTypeStr() const;

    bool setSoldierType(SoldierType soldierType);

    virtual qint16 attack(qint16 abilityType, qint16 attackNumber) = 0;

protected:
    void setType(Type type);

private:
    QString mCharName;
    QString mLifeForm;

    Type mType;
    QString mTypeStr;
    
    SoldierType mSoldierType;

    qint16 mLevel;
};
