#include<string>
#include "FightStats.h"
#include "GrapplingStats.h"
#include "StrikingStats.h"

using namespace std;


FightStats::FightStats()
{
    strikingStats = StrikingStats();
    grapplingStats = GrapplingStats();
}


FightStats::FightStats(const GrapplingStats& grapplingStats, const StrikingStats& strikingStats)
{
    this->grapplingStats = grapplingStats;
    this->strikingStats = strikingStats;
}

FightStats::FightStats(double averageKnockdowns, double strikingAccuracy,
           double takedownAccuracy, double strikesAttempted,
           double strikesLanded, double takedownsAttempted,
           double takedownsLanded)
{
    strikingStats = StrikingStats(averageKnockdowns, strikingAccuracy, strikesAttempted, strikesLanded);
    grapplingStats = GrapplingStats(takedownAccuracy, takedownsAttempted, takedownsLanded);
}

// GETTERS
// two getters for two variables

StrikingStats FightStats::getStrikingStats() const
{
    return strikingStats;
}

GrapplingStats FightStats::getGrapplingStats() const
{
    return grapplingStats;
}

// SETTERS
// two setters for two variables

void FightStats::setStrikingStats(const StrikingStats& strikingStats)
{
    this->strikingStats = strikingStats;
}

void FightStats::setGrapplingStats(const GrapplingStats& grapplingStats)
{
    this->grapplingStats = grapplingStats;
}

//METHODS
std::string FightStats::displayFightStats() const
{
    return strikingStats.displayStrikingStats() + " And"
    + grapplingStats.displayGrapplingStats();
}
