/*File Name: Car.h
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include <string>
#include "Vehicle.h"

class Car : public Vehicle {
public:
	//default constructor
	Car();

	//custom constructor
	Car(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway);

	//override the clone function from the vehicle parent class
	virtual Car* clone() const;

	//override the getType function from the vehicle parent class
	virtual std::string getType() const;

	//override the getRefuelTime function from the vehicle parent class
	virtual double getRefuelTime() const;

	//override the toString function from the vehicle parent class
	virtual std::string toString() const override;

};




#endif /* SRC_CAR_H_ */
