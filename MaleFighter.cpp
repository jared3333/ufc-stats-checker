#include<string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include<iomanip>
#include "Fight.h"
#include "Fighter.h"
#include "MaleFighter.h"
#include "WinsBy.h"
#include "PhysicalAttributes.h"

using namespace std;

MaleFighter::MaleFighter() : Fighter() {}

MaleFighter::MaleFighter(const std::string fighterName, const FightRecord& fighterFightRecord,
                        const PhysicalAttributes& physicalAttributes, const FightStats& fightStats) :
                            Fighter(fighterName, fighterFightRecord,
                                    physicalAttributes, fightStats) {}
//METHODS
void MaleFighter::displayWeightClass(std::vector<Fight>& fights) const
{
    enum weightClasses {
        Flyweight,
        Bantamweight,
        Featherweight,
        Lightweight,
        Welterweight,
        Middleweight,
        LightHeavyweight,
        Heavyweight,
        Catchweight
    };
    cout << getFighterName() << " is a male UFC fighter who has fought in the following"
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