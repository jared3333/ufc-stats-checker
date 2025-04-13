#include<string>
#include "FightRecord.h"

using namespace std;

FightRecord::FightRecord()
{
    wins = 0;
    losses = 0;
    winsBy = WinsBy();
}

FightRecord::FightRecord(int wins, int losses, const WinsBy& winsBy)
{
    this->wins = wins;
    this->losses = losses;
    this->winsBy = winsBy;
}

// GETTERS
// three getters for three variables
int FightRecord::getWins() const
{
    return wins;
}

int FightRecord::getLosses() const
{
    return losses;
}

WinsBy FightRecord::getWinsBy() const
{
    return winsBy;
}


// SETTERS
// three setters for three variables

void FightRecord::setWins(int wins)
{
    this->wins = wins;
}

void FightRecord::setLosses(int losses)
{
    this->losses = losses;
}

void FightRecord::setWinsBy(const WinsBy& winsBy)
{
    this->winsBy = winsBy;
}

//METHODS
std::string FightRecord::displayRecord() const
{
    return " holds a record of " + std::to_string(wins) + " wins and "
    + std::to_string(losses) + " losses.";
}
