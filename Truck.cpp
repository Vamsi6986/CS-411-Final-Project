/*File Name: Truck.cpp
 * Author: Dakota Swanson
 * Student ID: P853E744
 * Assignment Number: 4
 */

#include <string>
#include "Truck.h"
#include "Vehicle.h"


//default constructor
Truck::Truck() : Vehicle ()
{

}

//custom constructor
Truck::Truck(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway) : Vehicle(make, model, engineSize, engineCylinders,tankSize, mpgCity, mpgHighway)
{

}

//copy constructor - clone() returns a copy of truck
Truck* Truck::clone() const
{
	return new Truck(*this);
}


//returns truck's type in a string
std::string Truck::getType() const
{
	return "Truck";
}

//returns the refuel time for truck as a double
double Truck::getRefuelTime() const
{
	return 16.0;
}

//returns truck's information as a string
std::string Truck::toString() const {
	return getType() + ": " + Vehicle::toString();
}


