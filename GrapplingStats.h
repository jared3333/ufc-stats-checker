#ifndef GRAPPLINGSTATS_H
#define GRAPPLINGSTATS_H

#include <string>
#include <iostream>

// GrapplingStats class
/* class representing grappling stats of fighters in the Ultimate
Fighting Championship (UFC)
*/

class GrapplingStats
{
protected:
    double takedownAccuracy, takedownsAttempted, takedownsLanded;

public:
    // CONSTRUCTORS
    // default constructor
    GrapplingStats();

    GrapplingStats(double takedownAccuracy, double takedownsAttempted,
               double takedownsLanded);

    // GETTERS
    // three getters for three variables
    double getTakedownAccuracy() const;
    double getTakedownsAttempted() const;
    double getTakedownsLanded() const;

    // SETTERS
    // three setters for three variables
    void setTakedownAccuracy(double takedownAccuracy);
    void setTakedownsAttempted(double takedownsAttempted);
    void setTakedownsLanded(double takedownsLanded);

    // METHODS
    std::string displayGrapplingStats() const;
};

#endif //GRAPPLINGSTATS_H
