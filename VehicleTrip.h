/*FileName: VehicleTrip.h
 * Author: Dakota Swanson
 * Student ID: P853E744
 * Assignment Number: 4
 */


#ifndef SRC_VEHICLETRIP_H_
#define SRC_VEHICLETRIP_H_

#include <iostream>
#include <vector>

#include "Vehicle.h"
#include "TripParameters.h"
#include "Trip.h"

using namespace std;

//vehicletrip class to contain a vehicle and other info to calculate the min/max values of
	//fuel used, fuel added, etc..
class VehicleTrip
{
public:
	//default constructor
	VehicleTrip();

	//custom constructor
	VehicleTrip(Vehicle* vehicle, const Trip &trip, const TripParameters &tripParameters);

	//accessor to return vehicle info
	Vehicle* getVehicle() const;

	//accessor to return total city distance traveled
	double getDistanceTraveledCity() const;

	//accessor to return total highway distance traveled
	double getDistanceTraveledHighway() const;

	//accessor to return fuel added
	double getFuelAdded() const;

	//accessor to return fuel used (gallons)
	double getFuelUsed() const;

	//accessor to return fuel remaining in tank (gallons)
	double getFuelRemaining() const;

	//accessor to return number of fuel stops
	int getFuelStops() const;

	//accessor to return travel time in minutes
	double getTime() const;

	//accessor to return time traveled in days
	int getTimeNumDays() const;

	//accessor to return travel time in hours
	int getTimeNumHours() const;

	//accessor to return travel time in minutes
	int getTimeNumMinutes() const;

	//accessor to return cost of fuel added to tank
	double getFuelAddedCost() const;

	//accessor to return cost of fuel used in car
	double getFuelUsedCost() const;

	//accessor to compare if travel time of one vehicle is less than the other
	bool isTimeLessThan(const VehicleTrip &vehicleTrip) const;

	//compares to vehicles and returns a bool value comparing which spent more time traveling
	bool isTimeMoreThan(const VehicleTrip &vehicleTrip) const;

	// Return true/false whether vehicle trip costs less based on fuel added
	bool isFuelAddedCostLessThan(const VehicleTrip &vehicleTrip) const;

	// Return true/false whether vehicle trip costs more based on fuel added
	bool isFuelAddedCostMoreThan(const VehicleTrip &vehicleTrip) const;

	// Return true/false whether vehicle trip costs less based on fuel used
	bool isFuelUsedCostLessThan(const VehicleTrip &vehicleTrip) const;

	// Return true/false whether vehicle trip costs more based on fuel used
	bool isFuelUsedCostMoreThan(const VehicleTrip &vehicleTrip) const;

	// Returns true/false whether vehicle trip is valid (initialized)
	bool isValid() const;

	// Overloaded insertion operator <<
	friend std::ostream &operator << (std::ostream &os, const VehicleTrip &vehicleTrip);

	//overloaded assignment operator
	VehicleTrip& operator= (const VehicleTrip &rhs);

	//copy function for vehicleTrip
	VehicleTrip(const VehicleTrip& vehTrip);

	//destructor for vehicleTrip
	~VehicleTrip();

	static bool compare(const VehicleTrip &vt1, const VehicleTrip &vt2);

private:
	Vehicle* vehicle;
	TripParameters tripParameters;
	double distanceTraveledCity;
	double distanceTraveledHighway;
	double fuelUsed;
	double fuelAdded;
	double fuelRemaining;
	int fuelStops;
	bool reachedDestination;
	bool initialized;
};

#endif /* SRC_VEHICLETRIP_H_ */
