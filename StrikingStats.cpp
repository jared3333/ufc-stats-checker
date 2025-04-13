#include<string>
#include "StrikingStats.h"
using namespace std;


StrikingStats::StrikingStats()
{
    averageKnockdowns = 0.0;
    strikingAccuracy = 0.0;
    strikesAttempted = 0.0;
    strikesLanded = 0.0;
}


StrikingStats::StrikingStats(double averageKnockdowns, double strikingAccuracy,
               double strikesAttempted, double strikesLanded)
{

    this->averageKnockdowns = averageKnockdowns;
    this->strikingAccuracy = strikingAccuracy;
    this->strikesAttempted = strikesAttempted;
    this->strikesLanded = strikesLanded;
}

// GETTERS
// four getters for four variables
double StrikingStats::getAverageKockdowns() const
{
    return averageKnockdowns;
}

double StrikingStats::getStrikingAccuracy() const
{
    return strikingAccuracy;
}

double StrikingStats::getStrikesAttempted() const
{
    return strikesAttempted;
}

double StrikingStats::getStrikesLanded() const
{
    return strikesLanded;
}

// SETTERS
// four setters for four variables

void StrikingStats::setAverageKockdowns(double averageKnockdowns)
{
    this->averageKnockdowns = averageKnockdowns;
}

void StrikingStats::setStrikingAccuracy(double strikingAccuracy)
{
    this->strikingAccuracy = strikingAccuracy;
}

void StrikingStats::setStrikesAttempted(double strikesAttempted)
{
    this->strikesAttempted = strikesAttempted;
}

void StrikingStats::setStrikesLanded(double strikesLanded)
{
    this->strikesLanded = strikesLanded;
}

//METHODS
std::string StrikingStats::displayStrikingStats() const
{
    return " lands an average of " + std::to_string(averageKnockdowns) + " knockdowns and "
        + std::to_string(strikesLanded) + " total strikes of " + std::to_string(strikesAttempted)
        + " attempted strikes, for a striking accuracy of " + std::to_string(strikingAccuracy)
        + ".";
}
