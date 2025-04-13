#include<string>
#include <iostream>
#include "Fight.h"
#include "Fighter.h"
#include "Referee.h"
#include "TitleFight.h"

using namespace std;

TitleFight::TitleFight() : Fight() {}

TitleFight::TitleFight(const Fighter& blueFighter, const Fighter& redFighter,
             const Referee& referee, const std::string& weightClass,
             const std::string& winner, int boutNumber,
             const std::string& location, const std::string& date)
                : Fight(blueFighter, redFighter, referee, weightClass,
                winner, boutNumber, location, date) {}


//METHODS
void TitleFight::displayFight()
{
    std::cout << "Displaying fight: \n" << std::endl;
    std::cout << std::right
            << std::setw(10) << "Red Corner"
            << std::setw(29) << "Blue Corner"
            << std::setw(32) << "Weight Class"
            << std::setw(14) << "Winner"
            << std::setw(10) << "R Wins"
            << std::setw(10) << "R Losses"
            << std::setw(8) << "B Wins"
            << std::setw(10) << "B Losses"
            << std::setw(13) << "Bout Number"
            << std::endl;
    std::cout << std::string(136, '-') << std::endl;
    std::cout << "\033[33m" << *this << std::endl << "\033[0m";
}

// OVERLOADED OPERATORS

void TitleFight::print(std::ostream& outs) {
    outs << "\033[33m";  // Set yellow color for TitleFight
    Fight::print(outs);  // Call base class print() to reuse formatting
    outs << "\033[0m";  // Append text and reset color
}