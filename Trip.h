/*File Name: Trip.h
 * Author: Dakota Swanson
 * Student ID: P853E744
 * Assignment Number: 4
 */

#ifndef SRC_TRIP_H_
#define SRC_TRIP_H_

#include <vector>

#include "TripLeg.h"

/**
 * The Trip class identifies properties of a trip (route)
 */
class Trip {
public:
	// Default constructor
	Trip();

	// Accessor to return list of trip legs
	std::vector<TripLeg> getLegs() const;

	// Accessor to return the number of trip legs
	int getNumberLegs() const;

	// Accessor to return the trip leg for the index provided
	TripLeg getLeg(int index) const;

	// Accessor to return the total distance traveled (miles)
	double getTotalDistance() const;

	// Accessor to return the distance traveled in the city (miles)
	double getCityDistance() const;

	// Accessor to return the distance traveled on the highway (miles)
	double getHighwayDistance() const;

private:
	// Instance variables
	std::vector<TripLeg> tripLegs;
};



#endif /* SRC_TRIP_H_ */
