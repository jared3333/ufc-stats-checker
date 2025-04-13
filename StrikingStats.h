#ifndef STRIKINGSTATS_H
#define STRIKINGSTATS_H

#include <string>
#include <iostream>

// StrikingStats class
/* class representing striking stats of fighters in the Ultimate
Fighting Championship (UFC)
*/

class StrikingStats
{
protected:
    double averageKnockdowns, strikingAccuracy, strikesAttempted,
      strikesLanded;

public:
    // CONSTRUCTORS
    // default constructor
    StrikingStats();

    StrikingStats(double averageKnockdowns, double strikingAccuracy,
               double strikesAttempted, double strikesLanded);

    // GETTERS
    // four getters for four variables
    double getAverageKockdowns() const;
    double getStrikingAccuracy() const;
    double getStrikesAttempted() const;
    double getStrikesLanded() const;

    // SETTERS
    // four setters for four variables
    void setAverageKockdowns(double averageKnockdowns);
    void setStrikingAccuracy(double strikingAccuracy);
    void setStrikesAttempted(double strikesAttempted);
    void setStrikesLanded(double strikesLanded);

    // METHODS
    std::string displayStrikingStats() const;
};

#endif //STRIKINGSTATS_H
