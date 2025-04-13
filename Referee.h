#ifndef REFEREE_H
#define REFEREE_H

#include <string>
#include <iostream>

// Referee class
/* class representing fighters in the Ultimate Fighting Championship (UFC)
 * Fields:
 * fighterName -
 * fighterWins - an int containing the number of wins on the fighter's record
 * fighterLosses - an int containing the number of losses on the fighter's record
*/

class Referee
{
protected:
    std::string refereeName;

public:
    // CONSTRUCTORS
    // default constructor
    Referee();

    Referee(std::string refereeName);

    // GETTERS
    // three getters for three variables
    std::string getRefereeName() const;

    // SETTERS
    // three setters for three variables
    void setRefereeName(std::string refereeName);

    // METHODS
    void displayRecord() const;

    // OVERLOADED OPERATORS
    bool operator == (const Referee& otherReferee) const {
        return refereeName == otherReferee.refereeName;
    }

    bool operator < (const Referee& otherReferee) const {
        return refereeName < otherReferee.refereeName;
    }

    bool operator > (const Referee& otherReferee) const {
        return refereeName > otherReferee.refereeName;
    }

    friend std::ostream& operator << (std::ostream& outs, const Referee& rObj)
    {
        outs << rObj.getRefereeName();
        return outs;
    }
};

#endif //REFEREE_H
