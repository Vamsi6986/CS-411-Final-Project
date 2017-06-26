/* File Name: Van.cpp
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#include "Van.h"
#include "Vehicle.h"

//default constructor
Van::Van() : Vehicle()
{
	//intentionally empty
}

//custom constructor
Van::Van(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway) : Vehicle(make, model, engineSize, engineCylinders,tankSize, mpgCity, mpgHighway)
{
	//intentionally empty
}

//returns van's type as a string
std::string Van::getType() const
{
	return "Van";
}

//returns van's refuel time as a double
double Van::getRefuelTime() const
{
	return 12.0;
}

//returns a copy of van
Van* Van::clone() const {
	return new Van(*this);
}

//returns van's information in string format
std::string Van::toString() const {
	return getType() + ": " + Vehicle::toString();
}
