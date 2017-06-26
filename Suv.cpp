/*File Name: Suv.cpp
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#include <string>
#include "Suv.h"



Suv::Suv() : Vehicle ()
{
	//deliberately empty
}


Suv::Suv(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway) : Vehicle(make, model, engineSize, engineCylinders,tankSize, mpgCity, mpgHighway)
{
	//deliberately empty
}

//returns SUV's type as a string
std::string Suv::getType() const
{
	return "SUV";
}

//returns refuel time as a double
double Suv::getRefuelTime() const
{
	return 10.0;
}

//returns a copy of suv
Suv* Suv::clone() const {
	return new Suv(*this);
}

//returns suvs information in a string
std::string Suv::toString() const {
	return getType() + ": " + Vehicle::toString();
}

