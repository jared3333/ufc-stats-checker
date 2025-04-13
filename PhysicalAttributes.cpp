//
// Created by jared on 9/1/24.
//
#include<string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include<iomanip>
#include "Fight.h"
#include "Fighter.h"
#include "PhysicalAttributes.h"
using namespace std;

/* trimString function
 * trims string (not original)
*/
std::string trimStringPhysicalAttributes(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    return (start == std::string::npos || end == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

PhysicalAttributes::PhysicalAttributes()
{
    fighterAge = 0;
    fighterStance = "N/A";
    fighterHeight = 0.0;
    fighterReach = 0.0;
}

PhysicalAttributes::PhysicalAttributes(int fighterAge, std::string fighterStance,
                                       double fighterHeight, double fighterReach)
{
    fighterStance.erase(std::remove(fighterStance.begin(),
    fighterStance.end(), '\n'), fighterStance.end());
    fighterStance.erase(std::remove(fighterStance.begin(),
    fighterStance.end(), '\r'), fighterStance.end());
    trimStringPhysicalAttributes(fighterStance);
    this->fighterAge = fighterAge;
    this->fighterStance = fighterStance;
    this->fighterHeight = fighterHeight;
    this->fighterReach = fighterReach;
}

// GETTERS
// four getters for four variables
int PhysicalAttributes::getAge() const
{
    return fighterAge;
}

std::string PhysicalAttributes::getStance() const
{
    return fighterStance;
}

double PhysicalAttributes::getHeight() const
{
    return fighterHeight;
}

double PhysicalAttributes::getReach() const
{
    return fighterReach;
}

// SETTERS
// four setters for four variables

void PhysicalAttributes::setAge(int fighterAge)
{
    this->fighterAge = fighterAge;
}

void PhysicalAttributes::setStance(std::string fighterStance)
{
    fighterStance.erase(std::remove(fighterStance.begin(),
    fighterStance.end(), '\n'), fighterStance.end());
    fighterStance.erase(std::remove(fighterStance.begin(),
    fighterStance.end(), '\r'), fighterStance.end());
    trimStringPhysicalAttributes(fighterStance);
    this->fighterStance = fighterStance;
}

void PhysicalAttributes::setHeight(double fighterHeight)
{
    this->fighterHeight = fighterHeight;
}

void PhysicalAttributes::setReach(double fighterHeight)
{
    this->fighterHeight = fighterHeight;
}

//METHODS
std::string PhysicalAttributes::displayAttributes() const
{
    return " is " + std::to_string(fighterAge) + " years old, fights in a(n) "
        + fighterStance + " stance, stands "
        + std::to_string(fighterHeight) + "cm tall, with a "
        + std::to_string(fighterReach) + "cm reach.\n\n";
}
