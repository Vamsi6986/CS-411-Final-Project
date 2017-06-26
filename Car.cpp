/*File Name: Car.cpp
 * Author: Dakota Swanson
 * Student ID: *******
 * Assignment Number: 4
 */
#include <string>
#include "Car.h"
#include "Vehicle.h"



//default constructor
Car::Car() : Vehicle ()
{

}


Car::Car(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway) : Vehicle(make, model, engineSize, engineCylinders,tankSize, mpgCity, mpgHighway)
{

}

//copy constructor - clone()


std::string Car::getType() const
{
	return "Car";
}


double Car::getRefuelTime() const
{
	return 8.0;
}

Car* Car::clone() const {
	return new Car(*this);
}

std::string Car::toString() const {
	return getType() + ": " + Vehicle::toString();
}


//clone() function returns a pointer to a new copy of the car (utilizing the default copy constructor)

//getType() function returns a string ("Car") for the car's type

//getRefuelTime() function returns 8.0 as a double (use a constant) for the number of minutes a car needs to refuel at a gas station

//toString() function redefines (overrides) the toString() function within the base class and returns a string consisting of the vehicle's type



