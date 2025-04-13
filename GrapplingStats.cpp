#include<string>
#include "GrapplingStats.h"
using namespace std;


GrapplingStats::GrapplingStats()
{
    takedownAccuracy = 0.0;
    takedownsAttempted = 0.0;
    takedownsLanded = 0.0;
}


GrapplingStats::GrapplingStats(double takedownAccuracy, double takedownsAttempted,
               double takedownsLanded)
{
    this->takedownAccuracy = takedownAccuracy;
    this->takedownsAttempted = takedownsAttempted;
    this->takedownsLanded = takedownsLanded;
}

// GETTERS
// four getters for four variables

double GrapplingStats::getTakedownAccuracy() const
{
    return takedownAccuracy;
}

double GrapplingStats::getTakedownsAttempted() const
{
    return takedownsAttempted;
}

double GrapplingStats::getTakedownsLanded() const
{
    return takedownsLanded;
}

// SETTERS
// four setters for four variables

void GrapplingStats::setTakedownAccuracy(double takedownAccuracy)
{
    this->takedownAccuracy = takedownAccuracy;
}

void GrapplingStats::setTakedownsAttempted(double takedownsAttempted)
{
    this->takedownsAttempted = takedownsAttempted;
}

void GrapplingStats::setTakedownsLanded(double takedownsLanded)
{
    this->takedownsLanded = takedownsLanded;
}

//METHODS
std::string GrapplingStats::displayGrapplingStats() const
{
    return " lands " + std::to_string(takedownsLanded) + " takedowns of "
        + std::to_string(takedownsAttempted)+ " attempted takedowns, for a takedown accuracy of "
        + std::to_string(takedownAccuracy) + ".\n\n";
}
