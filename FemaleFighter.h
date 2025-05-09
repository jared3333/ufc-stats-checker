#ifndef FEMALEFIGHTER_H
#define FEMALEFIGHTER_H

#include "Fighter.h"
#include "Fight.h"

class FemaleFighter : public Fighter {
public:
    /**
     * Requires: nothing
     * Modifies: number_of_eyes
     * Effects: calls parent default constructor
     */
    FemaleFighter();

    /**
     * Requires: nothing
     * Modifies: number_of_eyes
     * Effects: calls parent non-default constructor
     */
 explicit FemaleFighter(std::string fighterName,
  const FightRecord& fighterFightRecord,
  const PhysicalAttributes& physicalAttributes,
  const FightStats& fightStats);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: randomly returns either "*Grabs you*" or "*[number_of_eyes] eyes watching you*".
     */
    void displayWeightClass(std::vector<Fight>& fights) const override;
};

#endif //FEMALEFIGHTER_H
