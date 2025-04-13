#ifndef FIGHTRECORD_H
#define FIGHTRECORD_H

#include <string>
#include <iostream>
#include "WinsBy.h"

// FightRecord class
/* class representing fight stats of fighters in the Ultimate
Fighting Championship (UFC)
*/

class FightRecord
{
protected:
    int wins, losses;
    WinsBy winsBy;

public:
    // CONSTRUCTORS
    // default constructor
    FightRecord();

    FightRecord(int wins, int losses, const WinsBy& winsBy);

    // GETTERS
    // three getters for three variables
    int getWins() const;
    int getLosses() const;
    WinsBy getWinsBy() const;

    // SETTERS
    // three setters for three variables
    void setWins(int wins);
    void setLosses(int losses);
    void setWinsBy(const WinsBy& winsBy);

    // METHODS
    std::string displayRecord() const;
};


#endif //FIGHTRECORD_H
