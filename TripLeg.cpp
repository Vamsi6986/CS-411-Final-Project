/*Filename: TripLeg.cpp
 * Author: Dakota Swanson
 * Student ID: P853E744
 * Assignment Number: 4
 */

#include <iostream>
#include "TripLeg.h"

TripLeg::TripLeg() : distance(0.0), type(CITY)
{
}



TripLeg::TripLeg(double distance, Type type) : distance(distance), type(type)
{
}

/*
//custom constructor
TripLeg::TripLeg(double d, int t)
{
	distance = d;
	type = t;
}



//getter functions to get variables
int TripLeg::getType()
{
	return type;
}

double TripLeg::getDistance()
{
	return distance;
}
*/


double TripLeg::getDistance() const
{
	return distance;
}

/**
 * Accessor to return trip leg's type (city or highway)
 */
TripLeg::Type TripLeg::getType() const
{
	return type;
}

/**
 * Accessor to return true/false whether trip leg's type is city
 */
bool TripLeg::isCity() const
{
	return (type == CITY);
}

/**
 * Accessor to return true/false whether trip leg's type is highway
 */
bool TripLeg::isHighway() const
{
	return (type == HIGHWAY);
}
