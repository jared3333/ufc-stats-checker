#include<string>
#include "Referee.h"
using namespace std;

/* trimString function
 * trims string (not original)
*/
std::string trimStringReferee(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    return (start == std::string::npos || end == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

Referee::Referee()
{
    refereeName = "N/A";
}

Referee::Referee(std::string refereeName)
{
    refereeName.erase(std::remove(refereeName.begin(),
    refereeName.end(), '\n'), refereeName.end());
    refereeName.erase(std::remove(refereeName.begin(),
    refereeName.end(), '\r'), refereeName.end());
    trimStringReferee(refereeName);
    this->refereeName = refereeName;
}

// GETTERS
// getter for variable
std::string Referee::getRefereeName() const
{
    return refereeName;
}

// SETTERS
// setter for variable
void Referee::setRefereeName(std::string refereeName)
{
    refereeName.erase(std::remove(refereeName.begin(),
        refereeName.end(), '\n'), refereeName.end());
    refereeName.erase(std::remove(refereeName.begin(),
    refereeName.end(), '\r'), refereeName.end());
    trimStringReferee(refereeName);
    this->refereeName = refereeName;
}