#ifndef FIGHTER_H
#define FIGHTER_H
#include <string>
#include <vector>
#include "WinsBy.h"
#include "Fight.h"
#include "PhysicalAttributes.h"
#include "FightStats.h"
#include "FightRecord.h"

// Fighter class
/* class representing fighters in the Ultimate Fighting Championship (UFC)
 * Fields:
 * fighterName -
 * fighterWins - an int containing the number of wins on the fighter's record
 * fighterLosses - an int containing the number of losses on the fighter's record
*/

class Fight;

class Fighter
{
protected:
    std::string fighterName;
    FightRecord fighterFightRecord;
    PhysicalAttributes fighterAttributes;
    FightStats fighterFightStats;

public:
    // CONSTRUCTORS
    // default constructor
    Fighter();

    Fighter(std::string fighterName,
        const FightRecord& fighterFightRecord,
        const PhysicalAttributes& fighterAttributes,
        const FightStats& fighterFightStats);

    // GETTERS
    // four getters for four variables
    std::string getFighterName() const;
    FightRecord getFighterFightRecord() const;
    PhysicalAttributes getFighterAttributes() const;
    FightStats getFighterFightStats() const;

    // SETTERS
    // four setters for four variables
    void setFighterName(std::string fighterName);
    void setFighterFightRecord(const FightRecord& fighterFightRecord);
    void setFighterAttributes(const PhysicalAttributes& fighterAttributes);
    void setFighterFightStats(const FightStats& fighterFightStats);

    // METHODS
    void displayRecord() const;
    void displayAttributes() const;
    void displayWinsBy() const;
    void displayFightStats() const;
    virtual void displayWeightClass(std::vector<Fight>& fights) const;

    // OVERLOADED OPERATORS
    bool operator == (const Fighter& otherFighter) const {
        return fighterName == otherFighter.fighterName;
    }

    bool operator < (const Fighter& otherFighter) const {
        return fighterName < otherFighter.fighterName;
    }

    bool operator > (const Fighter& otherFighter) const {
        return fighterName > otherFighter.fighterName;
    }

    friend std::ostream& operator << (std::ostream& outs, const Fighter& fObj)
    {
        outs << fObj.getFighterName();
        return outs;
    }
};

#endif //FIGHTER_H
