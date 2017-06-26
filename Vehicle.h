/*File Name: Vehicle.h
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#ifndef SRC_VEHICLE_H_
#define SRC_VEHICLE_H_

#include <ostream>
#include <string>

/**
 * The Vehicle class identifies properties of a vehicle
 */
class Vehicle {
public:
	// Default constructor
	Vehicle();

	// Constructor allowing caller to specify a vehicle's make, model,
	//  engine size (in liters), number of cylinders, tank size (in gallons),
	//  and MPG rating (both city and highway)
	Vehicle(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway);

	// Accessor to return vehicle's make
	std::string getMake() const;

	// Accessor to return vehicle's model
	std::string getModel() const;

	// Accessor to return vehicle's engine size (in liters)
	double getEngineSize() const;

	// Accessor to return vehicle's number of cylinders
	int getEngineCylinders() const;

	// Accessor to return vehicle's tank size (in gallons)
	double getTankSize() const;

	// Accessor to return vehicle's MPG rating in the city
	int getMpgCity() const;

	// Accessor to return vehicle's MPG rating on the highway
	int getMpgHighway() const;

	// Returns true/false whether vehicle is valid (initialized)
	bool isValid() const;

	// Overloaded insertion operator <<
	friend std::ostream &operator <<(std::ostream &os, const Vehicle &vehicle);

	//virtual destructor
	virtual ~Vehicle();

	//pure virtual (abstract) member function clone() to return a pointer to a new copy (clone) of the object
	virtual Vehicle* clone() const = 0;

	//pure virtual (abstract) member function getType() within the class Vehicle to return the vehicle's type as a string
	virtual std::string getType() const = 0;

	//pure virtual (abstract) member function getRefuelTime() to return Vehicle's time to refuel in minutes
	virtual double getRefuelTime() const = 0;

	//toString function to return a formatted string of the vehicle's attributes, but not type
	virtual std::string toString() const;


private:
	// Instance variables
	bool initialized;
	std::string make;
	std::string model;
	double engineSize;
	int engineCylinders;
	double tankSize;
	int mpgCity;
	int mpgHighway;
};



#endif /* SRC_VEHICLE_H_ */
