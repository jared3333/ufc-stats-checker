#ifndef FIGHTSTATS_H
#define FIGHTSTATS_H

#include <string>
#include <iostream>
#include "GrapplingStats.h"
#include "StrikingStats.h"

// FightStats class
/* class representing fight stats of fighters in the Ultimate
Fighting Championship (UFC)
*/

class FightStats
{
protected:
    GrapplingStats grapplingStats;
    StrikingStats strikingStats;

public:
    // CONSTRUCTORS
    // default constructor
    FightStats();

    FightStats(const GrapplingStats& grapplingStats, const StrikingStats& strikingStats);

    FightStats(double averageKnockdowns, double strikingAccuracy,
               double takedownAccuracy, double strikesAttempted,
               double strikesLanded, double takedownsAttempted,
               double takedownsLanded);

    // GETTERS
    // two getters for two variables
    StrikingStats getStrikingStats() const;
    GrapplingStats getGrapplingStats() const;

    // SETTERS
    // two setters for two variables
    void setStrikingStats(const StrikingStats& strikingStats);
    void setGrapplingStats(const GrapplingStats& grapplingStats);

    // METHODS
    std::string displayFightStats() const;
};

#endif //FIGHTSTATS_H
