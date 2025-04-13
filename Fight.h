#ifndef FIGHT_H
#define FIGHT_H
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Fighter.h"
#include "Referee.h"

// Fight class
/* class representing fights in the Ultimate Fighting Championship (UFC)
 *Fields:
 * blueFighter - a string containing the first and last name of the fighter in the blue corner
 * redFighter - a string containing the first and last name of the fighter in the red corner
 * weightClass - a string containing the name of the weight class for the fight
 * winner - a string containing the corner color of the winning fighter (blue or red)
 * blueWins - an int containing the number of wins on the blue fighter's record
 * blueLosses - an int containing the number of losses on the blue fighter's record
 * redWins - an int containing the number of wins on the red fighter's record
 * redLosses - an int containing the number of losses on the red fighter's record
*/

class Fight
{
private:
    Fighter blueFighter, redFighter;
    Referee referee;
    std::string weightClass, winner;
    int boutNumber;
    std::string location;
    std::string date;

public:
    // CONSTRUCTORS
    // default constructor
    Fight();

    Fight(const Fighter& blueFighter, const Fighter& redFighter,
          const Referee& referee, const std::string& weightClass,
          const std::string& winner, int boutNumber,
          const std::string& location, const std::string& date);

    // GETTERS
    // eight getters for eight variables
    Fighter& getBlueFighter();
    Fighter& getRedFighter();
    Referee& getReferee();
    std::string getWeightClass() const;
    std::string getWinner() const;
    int getBoutNumber() const;
    std::string getLocation() const;
    std::string getDate() const;

    // SETTERS
    // eight setters for eight variables
    void setBlueFighter(Fighter blueFighter);
    void setRedFighter(Fighter redFighter);
    void setReferee(Referee referee);
    void setWeightClass(std::string weightClass);
    void setWinner(std::string winner);
    void setBoutNumber(int boutNumber);
    void setLocation(std::string location);
    void setDate(std::string date);

    // METHODS
    void pickFavorite();
    virtual void displayFight();

    /*
     * Overload stream insertion operator
     */

    // Declare the base class stream insertion operator
    virtual void print(std::ostream& outs);

    friend std::ostream& operator<<(std::ostream& outs, Fight& fObj);

   virtual ~Fight() = default;  // Virtual destructor for proper cleanup
};

// GLOBAL FUNCTIONS
// getDataFromFile function
/* reads data from specified CSV file
 * takes a vector of Fights as an argument and modifies it
 * returns true if data is read successfully
 * returns false if data is not read successfully
*/
bool getDataFromFile(std::vector<Fight>& fights);

/*fightObjectTest function
 * Fight object tests to make sure constructors,
 * getters, setters are all working
 * returns a boolean for pass or fail
 */
bool fightObjectTest();

/* verifyAllFields function
 * Verifies that all fields received data from CSV file
 * successfully and prints to console if one did not
 * takes vector of fights as a parameter
 * returns void
 */
void verifyAllFields(std::vector<Fight>& objs);

#endif //FIGHT_H
