#include<string>
#include <iostream>
#include <vector>
#include "Fight.h"
#include "Fighter.h"
#include "WinsBy.h"
#include "PhysicalAttributes.h"
#include "FightStats.h"
#include "FightRecord.h"

using namespace std;

/* trimString function
 * trims string (not original)
*/
std::string trimStringFighter(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    return (start == std::string::npos || end == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

Fighter::Fighter()
{
    fighterName = "N/A";
    fighterFightRecord = FightRecord();
    fighterAttributes = PhysicalAttributes();
    fighterFightStats = FightStats();
}

Fighter::Fighter(std::string fighterName, const FightRecord& fighterFightRecord,
        const PhysicalAttributes& fighterAttributes, const FightStats& fighterFightStats)
{
    fighterName.erase(std::remove(fighterName.begin(),
    fighterName.end(), '\n'), fighterName.end());
    fighterName.erase(std::remove(fighterName.begin(),
    fighterName.end(), '\r'), fighterName.end());
    trimStringFighter(fighterName);
    this->fighterName = fighterName;
    this->fighterFightRecord = fighterFightRecord;
    this->fighterAttributes = fighterAttributes;
    this->fighterFightStats = fighterFightStats;
}

// GETTERS
// six getters for six variables
std::string Fighter::getFighterName() const
{
    return fighterName;
}

FightRecord Fighter::getFighterFightRecord() const
{
    return fighterFightRecord;
}

PhysicalAttributes Fighter::getFighterAttributes() const
{
    return fighterAttributes;
}

FightStats Fighter::getFighterFightStats() const
{
    return fighterFightStats;
}

// SETTERS
// six setters for six variables

void Fighter::setFighterName(std::string fighterName)
{
    fighterName.erase(std::remove(fighterName.begin(),
        fighterName.end(), '\n'), fighterName.end());
    fighterName.erase(std::remove(fighterName.begin(),
    fighterName.end(), '\r'), fighterName.end());
    trimStringFighter(fighterName);
    this->fighterName = fighterName;
}

void Fighter::setFighterFightRecord(const FightRecord& fighterFightRecord)
{
    this->fighterFightRecord = fighterFightRecord;
}

void Fighter::setFighterAttributes(const PhysicalAttributes& fighterAttributes)
{
    this->fighterAttributes = fighterAttributes;
}

void Fighter::setFighterFightStats(const FightStats& fighterFightStats)
{
    this->fighterFightStats = fighterFightStats;
}

//METHODS
void Fighter::displayRecord() const
{
    cout << fighterName << fighterFightRecord.displayRecord() << endl << endl;
}

void Fighter::displayAttributes() const
{
    cout << fighterName << fighterAttributes.displayAttributes();
}

void Fighter::displayWinsBy() const
{
    cout << fighterName << fighterFightRecord.getWinsBy().displayWinsBy() << endl << endl;
}

void Fighter::displayFightStats() const
{
    cout << fighterName << fighterFightStats.displayFightStats();
}

void Fighter::displayWeightClass(std::vector<Fight>& fights) const
{
    enum weightClasses {
        WomenStrawweight,
        WomenFlyweight,
        WomenBantamweight,
        WomenFeatherweight,
        Flyweight,
        Bantamweight,
        Featherweight,
        Lightweight,
        Welterweight,
        Middleweight,
        LightHeavyweight,
        Heavyweight,
        Catchweight
    };

    for(Fight fight : fights)
    {
        if (fight.getRedFighter().getFighterName() == fighterName ||
            fight.getBlueFighter().getFighterName() == fighterName)
        {
            cout << fight.getWeightClass() << endl;
        }
    } cout << endl;
}