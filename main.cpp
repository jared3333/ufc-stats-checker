#include "Fight.h"
#include "Fighter.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/* displayFights function
 * prints a few fight objects
*/
void displayFights(vector<Fight> f);

/* getIntFromUser function
 * prompts user for integer and validates
*/
int getIntFromUser(int limit);

/* toLower function
 * converts string to lowercase (not original)
*/
string toLower(string s);

/* getFightSelection function
 * prompts user to select a fight
*/
Fight getFightSelection(vector<Fight> fights);

/* getFighterSelection function
 * prompts user to select a fighter
*/
Fighter getFighterSelection(vector<Fight> fights);

/* getRefereeSelection function
 * prompts user to select a fighter
*/
Referee getRefereeSelection(vector<Fight> fights);

/* main function
 * calls functions from Fight.h
 * and displays objects from vector
*/
int main()
{
    // declare vector
    std::vector<Fight> fights;

    // run function to read data to vector
    if(getDataFromFile(fights)) {
        cout<<"Read in data successfully, size of vector: "<<fights.size()<<endl<<endl;
    }

    // main menu loop
    while (true) {
        cout << "Please choose one of these options: "
                "\n 0. Display fights\n 1. Select a fighter\n"
                " 2. Select a fight\n 3. Select a referee\n"
                " 4. Exit\n(Please enter 0, 1, 2, 3 or 4): ";
        const int selection = getIntFromUser(5);
        cout<<endl;

        if(selection == 0) {
            displayFights(fights);
        } if(selection == 1) {
            Fighter selectedFighter = getFighterSelection(fights);
            // sub-menu loop
            while (true) {
                cout << "Please choose one of these options: \n 0. Get fighter record"
                        "\n 1. Get fighter weight class\n 2. Get fighter attributes\n"
                        " 3. Get fighter win types\n 4. Get fighter fight stats \n 5. Exit\n"
                        "(Please enter 0, 1, 2, 3, 4 or 5): ";
                const int fSelection = getIntFromUser(5);
                cout<<endl;

                if(fSelection == 0) {
                    selectedFighter.displayRecord();
                } if(fSelection == 1) {
                    selectedFighter.displayWeightClass(fights);
                } if(fSelection == 2) {
                    selectedFighter.displayAttributes();
                } if(fSelection == 3) {
                    selectedFighter.displayWinsBy();
                } if(fSelection == 4) {
                    selectedFighter.displayFightStats();
                } if(fSelection == 5) {
                    break;
                }
            }
        } if(selection == 2) {
            Fight selectedFight = getFightSelection(fights);
            // sub-menu loop
            while (true) {
                cout << "Please choose one of these options: \n 0. Get fight prediction"
                        "\n 1. Display fight\n 2. Exit\n(Please enter 0, 1 or 2): ";
                const int fSelection = getIntFromUser(2);
                cout<<endl;

                if(fSelection == 0) {
                    selectedFight.displayFight();
                } if(fSelection == 1) {
                    selectedFight.pickFavorite();
                }
                if(fSelection == 2) {
                    break;
                }
            }
        } if(selection == 3)
        {
            Referee selectedReferee = getRefereeSelection(fights);
            // sub-menu loop
            while (true) {
                cout << "Please choose one of these options: \n 0. Get referee name"
                        "\n 1. Exit\n"
                        "(Please enter 0 or 1): ";
                const int rSelection = getIntFromUser(1);
                cout<<endl;

                if(rSelection == 0) {
                    cout << selectedReferee.getRefereeName() << endl << endl;
                } if(rSelection == 1) {
                    break;
                }
            }
        } if(selection == 4) {
                break;
            }
        }
    }

// FUNCTION IMPLEMENTATIONS:

Fight getFightSelection(vector<Fight> fights)
{
    std::vector<Fighter> potentialFighters;

    while (true) // until a valid number is entered
    {
        std::cout << "Enter the bout number: ";
        int inputInt = getIntFromUser(fights.size());
        cout << endl << "Selected fight number " << inputInt << endl << endl;
        return fights[inputInt - 1];
    }
}

Fighter getFighterSelection(vector<Fight> fights)
{
    string inputString;
    std::vector<Fighter> potentialFighters;

    while (true) // until a valid name is entered
    {
        while (true) // until input is >= 3 characters
        {
            std::cout << "Enter part of the fighter's name (at least three characters): ";
            getline(cin, inputString);
            if (inputString.length() > 2)
            {
                break;
            }
            cout << "Please enter at least three characters. " << endl;
        }

        inputString = toLower(inputString);

        for(Fight& fight : fights)
        {
            const Fighter& redFighter = fight.getRedFighter();
            const Fighter& blueFighter = fight.getBlueFighter();

            string redNameLC = toLower(redFighter.getFighterName());
            string blueNameLC = toLower(blueFighter.getFighterName());

            if(redNameLC.find(inputString) != string::npos)
            {
                bool isDuplicateRed = false;
                for(Fighter& fighter : potentialFighters)
                {
                    if (redFighter.getFighterName() == fighter.getFighterName())
                    {
                        isDuplicateRed = true;
                        break;
                    }
                }
                if (!isDuplicateRed) {
                    potentialFighters.push_back(redFighter);
                }
            }

            if(blueNameLC.find(inputString) != string::npos)
            {
                bool isDuplicateBlue = false;
                for(Fighter& fighter : potentialFighters)
                {
                    if (blueFighter.getFighterName() == fighter.getFighterName())
                    {
                        isDuplicateBlue = true;
                        break;
                    }
                }
                if(!isDuplicateBlue) {
                    potentialFighters.push_back(blueFighter);
                }
            }
        }
        if(!potentialFighters.empty())
        {
            break;
        }
        cout << "No results found. " << endl;
    }

    int n = 0;
    for (const Fighter& fighter : potentialFighters)
    {
        cout << n << ". " << fighter.getFighterName() << endl;
        ++n;
    }
    cout << "Select fighter (0-" << potentialFighters.size() - 1 << "): ";
    int selection = getIntFromUser(potentialFighters.size() - 1);
    Fighter selectedFighter = potentialFighters[selection];
    cout << endl << "Selected " << selectedFighter << endl << endl;
    return selectedFighter;
}

Referee getRefereeSelection(vector<Fight> fights)
{
    string inputString;
    std::vector<Referee> potentialReferees;

    while (true) // until a valid name is entered
    {
        std::cout << "Enter part of the referee's name (any number of characters): ";
        getline(cin, inputString);

        inputString = toLower(inputString);

        for(Fight& fight : fights)
        {
            const Referee& fightReferee = fight.getReferee();

            string fightRefereeLC = toLower(fightReferee.getRefereeName());

            if(fightRefereeLC.find(inputString) != string::npos)
            {
                bool isDuplicateRef = false;
                for(Referee& referee : potentialReferees)
                {
                    if (fight.getReferee().getRefereeName() == referee.getRefereeName())
                    {
                        isDuplicateRef = true;
                        break;
                    }
                }
                if (!isDuplicateRef) {
                    potentialReferees.push_back(fightReferee);
                }
            }
        }
        if(!potentialReferees.empty())
        {
            break;
        }
        cout << "No results found. " << endl;
    }

    int n = 0;
    for (const Referee& referee : potentialReferees)
    {
        cout << n << ". " << referee.getRefereeName() << endl;
        ++n;
    }
    cout << "Select referee (0-" << potentialReferees.size() - 1 << "): ";
    int selection = getIntFromUser(potentialReferees.size() - 1);
    Referee selectedReferee = potentialReferees[selection];
    cout << endl << "Selected " << selectedReferee << endl << endl;
    return selectedReferee;
}

void displayFights(vector<Fight> f){
    std::cout << "How many fights do you want to display (up to 100): ";
    const int numFights = getIntFromUser(100);
    std::cout << "Starting at what bout number? : ";
    const int startFight = getIntFromUser(6012 - numFights);

    std::cout << "Displaying fight objects: \n" << std::endl;
    std::cout << std::right
            << std::setw(10) << "Red Corner"
            << std::setw(31) << "Blue Corner"
            << std::setw(30) << "Weight Class"
            << std::setw(14) << "Winner"
            << std::setw(10) << "R Wins"
            << std::setw(10) << "R Losses"
            << std::setw(8) << "B Wins"
            << std::setw(10) << "B Losses"
            << std::setw(8) << "Bout #"
            << std::setw(9) << "Referee"
            << std::endl;
    std::cout << std::string(146, '-') << std::endl;

    for (int i = startFight; i < (startFight + numFights); i++) {
        std::cout << f.at(i) << std::endl;
    }
    std::cout << std::endl;
}

int getIntFromUser(const int limit) {
    string inputString;
    const string validDigits = "0123456789";

    getline(cin, inputString);

    int inputInt;
    while (true) {
        bool validInput = !inputString.empty();

        for (int i = 0; i < inputString.length(); i++) {
            if (validDigits.find(inputString[i]) == string::npos) {
                validInput = false;
                break;
            }
        }
        try {
            if (stoi(inputString) > limit || stoi(inputString) < 0)
            {
                validInput = false;
            }
            if (validInput) {
                inputInt = stoi(inputString);
                break;
            }
        } catch (out_of_range&) {
            cout << "Invalid input. Please enter an integer: ";
        } catch (invalid_argument&) {
            cout << "Invalid input. Please enter an integer: ";
        }

        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        getline(cin, inputString);
    }
    return inputInt;
}

string toLower(string s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}