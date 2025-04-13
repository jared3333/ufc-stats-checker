#ifndef PHYSICALATTRIBUTES_H
#define PHYSICALATTRIBUTES_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Fight.h"

// PhysicalAttributes class
/* class representing physical attributes of fighters in the Ultimate
Fighting Championship (UFC)
 * Fields:
 * fighterName -
 * fighterWins - an int containing the number of wins on the fighter's record
 * fighterLosses - an int containing the number of losses on the fighter's record
*/

class PhysicalAttributes
{
protected:
    int fighterAge;
    std::string fighterStance;
    double fighterHeight, fighterReach;

public:
    // CONSTRUCTORS
    // default constructor
    PhysicalAttributes();

    PhysicalAttributes(int fighterAge, std::string fighterStance,
        double fighterHeight, double fighterReach);

    // GETTERS
    // four getters for four variables
    int getAge() const;
    std::string getStance() const;
    double getHeight() const;
    double getReach() const;

    // SETTERS
    // four setters for four variables
    void setAge(int fighterAge);
    void setStance(std::string fighterStance);
    void setHeight(double fighterHeight);
    void setReach(double fighterReach);

    // METHODS
    std::string displayAttributes() const;

    // OVERLOADED OPERATORS
    /*
    bool operator == (const Fighter& otherFighter) const {
        return fighterName == otherFighter.fighterName;
    }

    bool operator < (const Fighter& otherFighter) const {
        return fighterName < otherFighter.fighterName;
    }

    bool operator > (const Fighter& otherFighter) const {
        return fighterName > otherFighter.fighterName;
    }

    friend std::ostream& operator << (std::ostream& outs, const Fighter& fObj)
    {
        outs << fObj.getFighterName();
        return outs;
    }
    */
};

#endif //PHYSICALATTRIBUTES_H
