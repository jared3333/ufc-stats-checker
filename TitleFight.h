#ifndef TITLEFIGHT_H
#define TITLEFIGHT_H

#include "Fighter.h"
#include "Referee.h"
#include "Fight.h"

class TitleFight : public Fight {
public:

    // NUMBER_OF_ROUNDS = 5;

    /**
     * Requires: nothing
     * Modifies: number_of_eyes
     * Effects: calls parent default constructor
     */
    TitleFight();

    /**
     * Requires: nothing
     * Modifies: number_of_eyes
     * Effects: calls parent non-default constructor
     */
    TitleFight(const Fighter& blueFighter, const Fighter& redFighter,
       const Referee& referee, const std::string& weightClass,
       const std::string& winner, int boutNumber,
       const std::string& location, const std::string& date);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: randomly returns either "*Grabs you*" or "*[number_of_eyes] eyes watching you*".
     */
    void displayFight() override;

    void print(std::ostream& outs) override;
};

#endif //TITLEFIGHT_H
