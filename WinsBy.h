#ifndef WINSBY_H
#define WINSBY_H

// WinsBy class
/* class representing the types of wins in the records of fighters in the
Ultimate Fighting Championship (UFC)
 * Fields:
 * fighterName -
 * fighterWins - an int containing the number of wins on the fighter's record
 * fighterLosses - an int containing the number of losses on the fighter's record
*/

class WinsBy
{
protected:
    int fighterDecisionWins, fighterTKOWins, fighterSubWins;

public:
    // CONSTRUCTORS
    // default constructor
    WinsBy();

    WinsBy(int fighterDecisionWins,
        int fighterTKOWins, int fighterSubWins);

    // GETTERS
    // three getters for three variables
    int getDecisionWins() const;
    int getTKOWins() const;
    int getSubWins() const;

    // SETTERS
    // three setters for three variables
    void setDecisionWins(int fighterDecisionWins);
    void setTKOWins(int fighterTKOWins);
    void setSubWins(int fighterSubWins);

    // METHODS
    std::string displayWinsBy() const;

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

#endif //WINSBY_H
