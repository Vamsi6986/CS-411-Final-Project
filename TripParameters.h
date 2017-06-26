/*FileName: TripParameters.cpp
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#ifndef TRIPPARAMETERS_H_
#define TRIPPARAMETERS_H_

#include <string>
#include <stdexcept>
#include <cstdlib>
#include <fstream>


class TripParameters
{
public:
	TripParameters();

	// Constructor to fetch input parameters from INI file provided
	TripParameters(const char filename[]) throw (std::ifstream::failure, std::invalid_argument, std::out_of_range);

	// Accessor to return the average speed in the city (MPH)
	double getMphCity() const;

	// Accessor to return the average speed on the highway (MPH)
	double getMphHighway() const;

	// Accessor to return the average fuel price per gallon
	double getFuelPrice() const;

	// Accessor to return the distance between gas stations (miles)
	double getDistanceBetweenGasStations() const;

	// Accessor to return the time between taking naps (hours)
	double getTimeBetweenNaps() const;

	// Accessor to return the time required to refuel (minutes)
//	int getRefuelTime() const;	not required for assignment 4

	// Accessor to return the time required to use the restroom (minutes)
	int getRestroomTime() const;

	// Accessor to return the time required to take a nap (minutes)
	int getNapTime() const;

private:
	double mphCity;
	double mphHighway;
	double fuelPrice;
	double distanceBetweenGasStations;
	double timeBetweenNaps;
	//int refuelTime; not needed for assignment 4
	int restroomTime;
	int napTime;


	void parseValue(std::string nameValuePair) throw (std::invalid_argument, std::out_of_range);
};



#endif /* SRC_TRIPPARAMETERS_H_ */
