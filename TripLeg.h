/*Filename: TripLeg.h
 * Author: Dakota Swanson
 * Student ID: P853E744
 * Assignment #: 4
 */

#ifndef SRC_TRIPLEG_H_
#define SRC_TRIPLEG_H_

#include <iostream>
#include <vector>

//class TripLeg to hold the information for distance each trip leg is
	//as well as the type, 0 for city and 1 for highway

class TripLeg {
public:
	// Enumerated type (city or highway) for trip leg
	enum Type { CITY, HIGHWAY };

	// Default constructor
	TripLeg();

	// Constructor allowing caller to specify a trip leg's distance (miles)
	//  and type (city or highway)
	TripLeg(double distance, Type type);

	// Accessor to return trip leg's distance (miles)
	double getDistance() const;

	// Accessor to return trip leg's type (city or highway)
	Type getType() const;

	// Accessor to return true/false whether trip leg's type is city
	bool isCity() const;

	// Accessor to return true/false whether trip leg's type is highway
	bool isHighway() const;

private:
	// Instance variables
	double distance;
	Type type;
};

/*
class TripLeg {
private:
	int type; //0 for city, 1 for highway
	double distance;
public:
	TripLeg();
	TripLeg(double d, int t);
	int getType();
	double getDistance();
};
*/

#endif /* SRC_TRIPLEG_H_ */
