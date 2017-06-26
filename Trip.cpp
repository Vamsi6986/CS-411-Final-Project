/*File Name: Trip.cpp
 * Author: Dakota Swanson
 * Student ID: P853E744
 * Assignment Number: 4
 */

#include "Trip.h"

/**
 * Default constructor
 */
Trip::Trip()
{
	// Initialize list of trip legs (trip route)
	tripLegs.push_back(TripLeg(3.3,   TripLeg::CITY));
	tripLegs.push_back(TripLeg(23.2,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.05,  TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.2,   TripLeg::CITY));
	tripLegs.push_back(TripLeg(56.2,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(50.3,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(6.8,   TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(53.5,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(21.3,  TripLeg::CITY));
	tripLegs.push_back(TripLeg(229.0, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(2.8,   TripLeg::CITY));
	tripLegs.push_back(TripLeg(74.7,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(47.3,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(69.3,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.2,   TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(24.3,  TripLeg::CITY));
	tripLegs.push_back(TripLeg(21.2,  TripLeg::CITY));
	tripLegs.push_back(TripLeg(79.2,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(208.0, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(181.3, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(86.6,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(106.7, TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(8.0,   TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(45.6,  TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.1,   TripLeg::CITY));
	tripLegs.push_back(TripLeg(0.5,   TripLeg::CITY));
	tripLegs.push_back(TripLeg(22.7,  TripLeg::HIGHWAY));
	tripLegs.push_back(TripLeg(0.6,   TripLeg::CITY));
	tripLegs.push_back(TripLeg(1.7,   TripLeg::CITY));
}

/**
 * Accessor to return list of trip legs
 */
std::vector<TripLeg> Trip::getLegs() const
{
	std::vector<TripLeg> tempTripLegs;

	for (int i = 0; i < (int) tripLegs.size(); i++)
		tempTripLegs.push_back(tripLegs[i]);
	return tempTripLegs;
}

/**
 * Accessor to return the number of trip legs
 */
int Trip::getNumberLegs() const
{
	return (int) tripLegs.size();
}

/**
 * Accessor to return the trip leg for the index provided
 */
TripLeg Trip::getLeg(int index) const
{
	if (index < 0 || index >= (int) tripLegs.size())
		return TripLeg();
	return tripLegs[index];
}

/**
 * Return the total distance traveled (miles)
 */
double Trip::getTotalDistance() const
{
	double totalDistance = 0.0;
	for (int i = 0; i < (int) tripLegs.size(); i++)
		totalDistance += tripLegs[i].getDistance();
	return totalDistance;
}

/**
 * Return the distance traveled in the city (miles)
 */
double Trip::getCityDistance() const
{
	double cityDistance = 0.0;
	for (int i = 0; i < (int) tripLegs.size(); i++)
		if (tripLegs[i].isCity())
			cityDistance += tripLegs[i].getDistance();
	return cityDistance;
}

/**
 * Return the distance traveled on the highway (miles)
 */
double Trip::getHighwayDistance() const
{
	double highwayDistance = 0.0;
	for (int i = 0; i < (int) tripLegs.size(); i++)
		if (tripLegs[i].isHighway())
			highwayDistance += tripLegs[i].getDistance();
	return highwayDistance;
}



