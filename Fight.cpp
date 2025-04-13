//
// Created by jared on 9/1/24.
//
#include<string>
#include <iostream>
#include <fstream>
#include <vector>
#include<iomanip>
#include "Fight.h"
#include "TitleFight.h"
#include "NonTitleFight.h"
#include "PhysicalAttributes.h"
#include "WinsBy.h"
#include "Fighter.h"
#include "Referee.h"
#include "FemaleFighter.h"
#include "MaleFighter.h"

using namespace std;

Fight::Fight()
    {
        blueFighter = Fighter();
        redFighter = Fighter();
        referee = Referee();
        weightClass = "N/A";
        winner = "N/A";
        boutNumber = 0;
        location = "N/A";
        date = "N/A";
    }


Fight::Fight(const Fighter& blueFighter, const Fighter& redFighter,
             const Referee& referee, const std::string& weightClass,
             const std::string& winner, int boutNumber,
             const std::string& location, const std::string& date)
    {
    this->blueFighter = blueFighter;
    this->redFighter = redFighter;
    this->referee = referee;
    this->weightClass = weightClass;
    this->winner = winner;
    this->boutNumber = boutNumber;
    this->location = location;
    this->date = date;
}

// GETTERS
// eight getters for eight variables
Fighter& Fight::getBlueFighter()
{
    return blueFighter;
}

Fighter& Fight::getRedFighter()
{
    return redFighter;
}

Referee& Fight::getReferee()
{
    return referee;
}

std::string Fight::getWeightClass() const
{
    return weightClass;
}

std::string Fight::getWinner() const
{
    return winner;
}

int Fight::getBoutNumber() const
{
    return boutNumber;
}

std::string Fight::getLocation() const
{
    return location;
}

std::string Fight::getDate() const
{
    return date;
}

// SETTERS
// eight setters for eight variables

void Fight::setBlueFighter(Fighter blueFighter)
{
    this->blueFighter = blueFighter;
}

void Fight::setRedFighter(Fighter redFighter)
{
    this->redFighter = redFighter;
}

void Fight::setReferee(Referee referee)
{
    this->referee = referee;
}

void Fight::setWeightClass(std::string weightClass)
{
    this->weightClass = weightClass;
}

void Fight::setWinner(std::string winner)
{
    this->winner = winner;
}

void Fight::setBoutNumber(int boutNumber)
{
    this->boutNumber = boutNumber;
}

void Fight::setLocation(std::string location)
{
    this->location = location;
}

void Fight::setDate(std::string date)
{
    this->date = date;
}

// METHODS
void Fight::pickFavorite()
{
    double redWinRate = static_cast<double>(redFighter.getFighterFightRecord().getWins()) / (redFighter.getFighterFightRecord().getLosses()
        + redFighter.getFighterFightRecord().getWins());
    double blueWinRate = static_cast<double>(blueFighter.getFighterFightRecord().getWins()) / (blueFighter.getFighterFightRecord().getLosses()
        + blueFighter.getFighterFightRecord().getWins());

    if (redWinRate > blueWinRate)
    {
        cout << redFighter.getFighterName() << " should be the favorite to win. " << endl << endl;
    }
    if (redWinRate < blueWinRate)
    {
        cout << blueFighter.getFighterName() << " should be the favorite to win. " << endl << endl;
    }
    if (redWinRate == blueWinRate)
    {
        cout << "It's an even fight " << endl << endl;
    }
}

void Fight::displayFight()
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
    std::cout << *this << std::endl;
}

// OVERLOADED OPERATORS

std::ostream& operator<<(std::ostream& outs, Fight& fObj) {
    fObj.print(outs);
    return outs;
}

void Fight::print(std::ostream& outs) {
    outs << std::left
         << std::setw(30) << getRedFighter().getFighterName()
         << std::setw(29) << getBlueFighter().getFighterName()
         << std::setw(20) << getWeightClass()
         << std::setw(10) << getWinner()
         << std::setw(8) << getRedFighter().getFighterFightRecord().getWins()
         << std::setw(10) << getRedFighter().getFighterFightRecord().getLosses()
         << std::setw(8) << getBlueFighter().getFighterFightRecord().getWins()
         << std::setw(10) << getBlueFighter().getFighterFightRecord().getLosses()
         << std::setw(8) << getBoutNumber()
         << std::setw(8) << getReferee();
}

// GLOBAL FUNCTIONS

// getDataFromFile function
/* reads data from specified CSV file
 * takes a vector of Fights as an argument and modifies it
 * returns true if data is read successfully
 * returns false if data is not read successfully
*/
bool getDataFromFile(vector<Fight>& fights) {
    // try to open file and announce it
    cout << "Opening file" << endl;
    ifstream fileIn;
    fileIn.open("../full_ufc_data.csv");

    // problem opening file; announce problem, return false
    if (!fileIn) {
        cout << "File not opened." << endl;
        return false;
    }

    // remove header from CSV file
    std::string header;
    getline(fileIn,header);

    // declare variables to be read in from file
    std::string redFighter, blueFighter, winner, weightClass, redStance, blueStance,
    newLine, refereeName, location, eventDate, titleFight;
    int blueWins, blueLosses, redWins, redLosses, boutNumber, blueAge, redAge,
    blueDecisionWins, blueTKOWins, blueSubWins, redDecisionWins, redTKOWins,
    redSubWins, deleteValue;
    double blueHeight, redHeight, blueReach, redReach, redTakedownsAttempted,
    redTakedownsLanded, redTakedownAccuracy, redStrikesAttempted, redStrikesLanded,
    redStrikingAccuracy, redKnockdowns, blueTakedownsAttempted,blueTakedownsLanded,
    blueTakedownAccuracy, blueStrikesAttempted, blueStrikesLanded, blueStrikingAccuracy,
    blueKnockdowns;
    char comma;

    // continue reading data while fileIn remains true,
    // and we have not yet reached the end of the file
    while (fileIn && fileIn.peek() != EOF){
        // initialize variables to sentinel values so we
        // can later identify any incorrectly set values
        redFighter = "N/A" , blueFighter = "N/A", winner = "N/A", weightClass = "N/A";
        blueWins = 999, blueLosses = 999, redWins = 999, redLosses = 999, boutNumber = 9999;

        // read in all strings
        if (!std::getline(fileIn, redFighter, ',')) {
            redFighter = "Unknown red fighter";
            fileIn.clear();
        }

        if (!std::getline(fileIn, blueFighter, ',')) {
            redFighter = "Unknown blue fighter";
            fileIn.clear();
        }

        if (!std::getline(fileIn, winner, ',')) {
            redFighter = "Unknown winner";
            fileIn.clear();
        }

        if (!std::getline(fileIn, weightClass, ',')) {
            redFighter = "Unknown weight class";
            fileIn.clear();
        }

        // read in red wins, then the comma
        fileIn>>redWins;
        if (fileIn.fail())
        {
            redWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in red losses, then the comma
        fileIn>>redLosses;
        if (fileIn.fail())
        {
            redLosses = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue wins, then the comma
        fileIn>>blueWins;
        if (fileIn.fail())
        {
            blueWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue losses, then the comma
        fileIn>>blueLosses;
        if (fileIn.fail())
        {
            blueLosses = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in bout number, then the comma
        fileIn>>boutNumber;
        if (fileIn.fail())
        {
            boutNumber = 8888;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue stance, then the comma
        if (!std::getline(fileIn, blueStance, ',')) {
            redFighter = "Unknown";
            fileIn.clear();
        }

        // read in blue height, then the comma
        fileIn >> blueHeight;
        if (fileIn.fail()) {
            blueHeight = 300.00; // default value if reading fails
            fileIn.clear(); // clear the fail state to continue reading
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue reach, then the comma
        fileIn >> blueReach;
        if (fileIn.fail()) {
            blueReach = 275.00; // default value if reading fails
            fileIn.clear(); // clear the fail state to continue reading
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue age, then the comma
        fileIn>>blueAge;
        if (fileIn.fail())
        {
            blueAge = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue wins by decision, then the comma
        fileIn>>blueDecisionWins;
        if (fileIn.fail())
        {
            blueDecisionWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue wins by KO/TKO, then the comma
        fileIn>>blueTKOWins;
        if (fileIn.fail())
        {
            blueTKOWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue wins by submission, then the comma
        fileIn>>blueSubWins;
        if (fileIn.fail())
        {
            blueSubWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in blue stance, then the comma
        if (!std::getline(fileIn, redStance, ',')) {
            redFighter = "Unknown";
            fileIn.clear();
        }

        // read in red height, then the comma
        fileIn >> redHeight;
        if (fileIn.fail()) {
            redHeight = 1000.00; // default value if reading fails
            fileIn.clear(); // clear the fail state to continue reading
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in red reach, then the comma
        fileIn >> redReach;
        if (fileIn.fail()) {
            redReach = 1000.00; // default value if reading fails
            fileIn.clear(); // clear the fail state to continue reading
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in red age, then the comma
        fileIn>>redAge;
        if (fileIn.fail())
        {
            redAge = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in red wins by decision, then the comma
        fileIn>>redDecisionWins;
        if (fileIn.fail())
        {
            redDecisionWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in red wins by KO/TKO, then the comma
        fileIn>>redTKOWins;
        if (fileIn.fail())
        {
            redTKOWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in red wins by submission, then the comma
        fileIn>>redSubWins;
        if (fileIn.fail())
        {
            redSubWins = 0;
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in referee name, then the comma
        if (!std::getline(fileIn, refereeName, ',')) {
            redFighter = "Unknown referee";
            fileIn.clear();
        }

        // read in the event date, then the comma
        fileIn>>eventDate;
        if (fileIn.fail()) {
            eventDate = "Unknown date";
            fileIn.clear();
        }
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        // read in event location, then the comma
        if (!std::getline(fileIn, location, ',')) {
            location = "Unknown location";
            fileIn.clear();
        }

        // read in blue knockdowns, then the comma
        fileIn>>blueKnockdowns;
        if (fileIn.fail())
        {
            blueKnockdowns = 0;
            fileIn.clear();
        }

        // read in blue strike accuracy, then the comma
        fileIn>>blueStrikingAccuracy;
        if (fileIn.fail())
        {
            blueStrikingAccuracy = 0;
            fileIn.clear();
        }

        // read in blue strikes landed, then the comma
        fileIn>>blueStrikesLanded;
        if (fileIn.fail())
        {
            blueStrikesLanded = 0;
            fileIn.clear();
        }

        // read in blue strikes attempted, then the comma
        fileIn>>blueStrikesAttempted;
        if (fileIn.fail())
        {
            blueStrikesAttempted = 0;
            fileIn.clear();
        }

        // read in blue takedown accuracy, then the comma
        fileIn>>blueTakedownAccuracy;
        if (fileIn.fail())
        {
            blueTakedownAccuracy = 0;
            fileIn.clear();
        }

        // read in blue takedowns landed, then the comma
        fileIn>>blueTakedownsLanded;
        if (fileIn.fail())
        {
            blueTakedownsLanded = 0;
            fileIn.clear();
        }

        // read in blue takedowns attempted, then the comma
        fileIn>>blueTakedownsAttempted;
        if (fileIn.fail())
        {
            blueTakedownsAttempted = 0;
            fileIn.clear();
        }

        // read in red knockdowns, then the comma
        fileIn>>redKnockdowns;
        if (fileIn.fail())
        {
            redKnockdowns = 0;
            fileIn.clear();
        }

        // read in red strike accuracy, then the comma
        fileIn>>redStrikingAccuracy;
        if (fileIn.fail())
        {
            redStrikingAccuracy = 0;
            fileIn.clear();
        }

        // read in red strikes landed, then the comma
        fileIn>>redStrikesLanded;
        if (fileIn.fail())
        {
            redStrikesLanded = 0;
            fileIn.clear();
        }

        // read in red strikes attempted, then the comma
        fileIn>>redStrikesAttempted;
        if (fileIn.fail())
        {
            redStrikesAttempted = 0;
            fileIn.clear();
        }

        // read in red takedown accuracy, then the comma
        fileIn>>redTakedownAccuracy;
        if (fileIn.fail())
        {
            redTakedownAccuracy = 0;
            fileIn.clear();
        }

        // read in red takedowns landed, then the comma
        fileIn>>redTakedownsLanded;
        if (fileIn.fail())
        {
            redTakedownsLanded = 0;
            fileIn.clear();
        }

        // read in red takedowns attempted, then the comma
        fileIn>>redTakedownsAttempted;
        if (fileIn.fail())
        {
            redTakedownsAttempted = 0;
            fileIn.clear();
        }

        // make sure a value is present for titleFight before reading,
        // since this is the last value on each line, and could be missing
        if (fileIn.peek() != '\r' && fileIn.peek() != '\n') {
            getline(fileIn, titleFight);
        }

        // convert titleFight to bool
        titleFight.erase(std::remove(titleFight.begin(),
    titleFight.end(), '\n'), titleFight.end());

        titleFight.erase(std::remove(titleFight.begin(),
        titleFight.end(), '\r'), titleFight.end());

        bool titleFightBool = false;
        if(titleFight == "FALSE")
        {
            titleFightBool = false;
        } else if(titleFight == "TRUE")
        {
            titleFightBool = true;
        }

        // create referee object
        Referee referee = Referee(refereeName);

        // create blue and red fighter objects
        std::unique_ptr<Fighter> newRedFighter;
        std::unique_ptr<Fighter> newBlueFighter;

        if (weightClass == "WomenStrawweight" || weightClass == "WomenFlyweight"
            || weightClass == "WomenBantamweight" || weightClass == "WomenFeatherweight")
        {
            newRedFighter = std::make_unique<FemaleFighter>(redFighter,
                                        FightRecord(redWins, redLosses, WinsBy(redDecisionWins, redTKOWins, redSubWins)),
                                        PhysicalAttributes(redAge, redStance, redHeight, redReach),
                                        FightStats(redKnockdowns, redStrikingAccuracy, redTakedownAccuracy,
                                                redStrikesAttempted, redStrikesLanded,
                                                redTakedownsAttempted,redTakedownsLanded));
            newBlueFighter = std::make_unique<FemaleFighter>(blueFighter,
                                        FightRecord(blueWins, blueLosses, WinsBy(blueDecisionWins, blueTKOWins, blueSubWins)),
                                        PhysicalAttributes(blueAge, blueStance, blueHeight, blueReach),
                                        FightStats(blueKnockdowns, blueStrikingAccuracy, blueTakedownAccuracy,
                                                blueStrikesAttempted, blueStrikesLanded,
                                                blueTakedownsAttempted,blueTakedownsLanded));
        } else
        {
            newRedFighter = std::make_unique<MaleFighter>(redFighter,
                                        FightRecord(redWins, redLosses, WinsBy(redDecisionWins, redTKOWins, redSubWins)),
                                        PhysicalAttributes(redAge, redStance, redHeight, redReach),
                                        FightStats(redKnockdowns, redStrikingAccuracy, redTakedownAccuracy,
                                                redStrikesAttempted, redStrikesLanded,
                                                redTakedownsAttempted,redTakedownsLanded));
            newBlueFighter = std::make_unique<MaleFighter>(blueFighter,
                                        FightRecord(blueWins, blueLosses, WinsBy(blueDecisionWins, blueTKOWins, blueSubWins)),
                                        PhysicalAttributes(blueAge, blueStance, blueHeight, blueReach),
                                        FightStats(blueKnockdowns, blueStrikingAccuracy, blueTakedownAccuracy,
                                                blueStrikesAttempted, blueStrikesLanded,
                                                blueTakedownsAttempted,blueTakedownsLanded));
        }

        // create a Fight object from the values read from the file, then add
        // that Fight object to the end of the vector passed into the function

        std::unique_ptr<Fight> newFight;

        if(titleFightBool)
        {
            newFight = std::make_unique<TitleFight>(*newBlueFighter, *newRedFighter, referee, weightClass,
            winner, boutNumber, location, eventDate);
        } else
        {
            newFight = std::make_unique<NonTitleFight>(*newBlueFighter, *newRedFighter, referee, weightClass,
            winner, boutNumber, location, eventDate);
        }

        fights.push_back(*newFight);
    }

    // close file, return true to confirm that data was read
    fileIn.close();
    return true;
}