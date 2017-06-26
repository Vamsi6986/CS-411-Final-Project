/*FileName: Vehicle.cpp
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#include <iostream>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ostream>
#include <string>

#include "Vehicle.h"

using namespace std;


static const char VEHICLE_STATS[] =
	"%s %s\n  Engine size: %.1fL %d cyl, Tank size: %.1f, MPG city: %d, MPG highway: %d";




//default constructor
Vehicle::Vehicle()
{
	initialized = false;
	// make[0] = '\0'; // Not necessary for type string
	// model[0] = '\0'; // Not necessary for type string
	engineSize = 0.0;
	engineCylinders = 0;
	tankSize = 0.0;
	mpgCity = 0;
	mpgHighway = 0;
}


//custom constructor
Vehicle::Vehicle(
	const std::string &make,
	const std::string &model,
	double engineSize,
	int engineCylinders,
	double tankSize,
	int mpgCity,
	int mpgHighway
)
{
	this->initialized = false;

	// Init other vehicle's attributes
	this->make = make;
	this->model = model;
	this->engineSize = engineSize;
	this->engineCylinders = engineCylinders;
	this->tankSize = tankSize;
	this->mpgCity = mpgCity;
	this->mpgHighway = mpgHighway;

	// Vehicle now initialized
	this->initialized = true;
}

//getter functions to retrieve the values of the private variables
string Vehicle::getMake() const
{
	return make;
}

string Vehicle::getModel() const
{
	return model;
}

double Vehicle::getEngineSize() const
{
	return engineSize;
}

/**
 * Accessor to return vehicle's number of cylinders
 */
int Vehicle::getEngineCylinders() const
{
	return engineCylinders;
}

/**
 * Accessor to return vehicle's tank size (in gallons)
 */
double Vehicle::getTankSize() const
{
	return tankSize;
}

/**
 * Accessor to return vehicle's MPG rating in the city
 */
int Vehicle::getMpgCity() const
{
	return mpgCity;
}

/**
 * Accessor to return vehicle's MPG rating on the highway
 */
int Vehicle::getMpgHighway() const
{
	return mpgHighway;
}

/**
 * Returns true/false whether vehicle is valid (initialized)
 */
bool Vehicle::isValid() const
{
	return initialized;
}


std::ostream &operator <<(std::ostream &os, const Vehicle &vehicle)
{
	// Output formatted string
	os << vehicle.toString();

	return os;
}

Vehicle::~Vehicle() {
	//intentionally empty
}

std::string Vehicle::toString() const {
	char str[200];

	sprintf(str, VEHICLE_STATS, make.c_str(), model.c_str(), engineSize, engineCylinders, tankSize, mpgCity, mpgHighway);

	return std::string(str);
}
