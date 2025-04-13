#include<string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include<iomanip>
#include "Fight.h"
#include "Fighter.h"
#include "FemaleFighter.h"
using namespace std;

FemaleFighter::FemaleFighter() : Fighter() {}

FemaleFighter::FemaleFighter(const std::string fighterName, const FightRecord& fighterFightRecord,
                        const PhysicalAttributes& physicalAttributes, const FightStats& fightStats) :
                            Fighter(fighterName, fighterFightRecord,
                                    physicalAttributes, fightStats) {}


//METHODS

void FemaleFighter::displayWeightClass(std::vector<Fight>& fights) const
{
    enum weightClasses {
        WomenStrawweight,
        WomenFlyweight,
        WomenBantamweight,
        WomenFeatherweight,
    };

    cout << getFighterName() << " is a female UFC fighter who has fought in the following"
                            " weight classes: " << endl;
    cout << "(Most recent)" << endl;
    for(Fight& fight : fights)
    {
        if (fight.getRedFighter().getFighterName() == fighterName ||
            fight.getBlueFighter().getFighterName() == fighterName)
        {
            cout << fight.getWeightClass() << endl;
        }
    } cout << "(UFC debut)" << endl << endl;
}