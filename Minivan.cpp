/*File Name: Minivan.cpp
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#include "Minivan.h"
#include "Vehicle.h"

//default constructor
Minivan::Minivan() : Vehicle ()
{
	//deliberately empty
}


Minivan::Minivan(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway) : Vehicle(make, model, engineSize, engineCylinders,tankSize, mpgCity, mpgHighway)
{
	//deliberately empty
}

//returns type of car in a string
std::string Minivan::getType() const
{
	return "Minivan";
}

//returns refuel time as a double
double Minivan::getRefuelTime() const
{
	return 14.0;
}

//clone function to make a copy of minivan
Minivan* Minivan::clone() const
{
	return new Minivan(*this);
}

//returns all of minivan's info as a string
std::string Minivan::toString() const
{
	return getType() + ": " + Vehicle::toString();
}
