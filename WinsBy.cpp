#include<string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include<iomanip>
#include "Fight.h"
#include "Fighter.h"
#include "PhysicalAttributes.h"
using namespace std;

WinsBy::WinsBy()
{
    fighterDecisionWins = 0;
    fighterTKOWins = 0;
    fighterSubWins = 0;
}

WinsBy::WinsBy(int fighterDecisionWins, int fighterTKOWins, int fighterSubWins)
{
    this->fighterDecisionWins = fighterDecisionWins;
    this->fighterTKOWins = fighterTKOWins;
    this->fighterSubWins = fighterSubWins;
}

// GETTERS
// three getters for four variables
int WinsBy::getDecisionWins() const
{
    return fighterDecisionWins;
}

int WinsBy::getTKOWins() const
{
    return fighterTKOWins;
}

int WinsBy::getSubWins() const
{
    return fighterSubWins;
}


// SETTERS
// three setters for four variables

void WinsBy::setDecisionWins(int fighterDecisionWins)
{
    this->fighterDecisionWins = fighterDecisionWins;
}

void WinsBy::setTKOWins(int fighterTKOWins)
{
    this->fighterTKOWins = fighterTKOWins;
}

void WinsBy::setSubWins(int fighterSubWins)
{
    this->fighterSubWins = fighterSubWins;
}

//METHODS
std::string WinsBy::displayWinsBy() const
{
    return " holds " + std::to_string(fighterDecisionWins) + " wins by decision, "
    + std::to_string(fighterTKOWins) + " wins by KO/TKO, and "
    + std::to_string(fighterSubWins) + " wins by submission.\n\n";
}
