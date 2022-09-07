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

    int getHealth() const;

    void setHealth(int health);

    int getArmor() const;

    void setArmor(int armor);

    Type getType() const;

    QString getLifeForm() const;

    void setLifeForm(QString lifeForm);

    SoldierType getSoldierType() const;

    bool setSoldierType(SoldierType soldierType);

    virtual qint16 attack(qint16 abilityType, qint16 attackNumber) = 0;

protected:
    void setType(Type type);

private:
    qint16 mHealth;
    qint16 mArmor;

    QString mLifeForm;

    Type mType;
    QString mTypeStr;
    
    SoldierType mSoldierType;
    QString mSoldierTypeStr;

};
