/*
 *File Name: Van.h
 *Author: Dakota Swanson
 */

#ifndef SRC_VAN_H_
#define SRC_VAN_H_

#include <string>
#include "Vehicle.h"

class Van : public Vehicle {
public:
	//default constructor
	Van();

	//custom constructor
	Van(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway);

	//override the clone function from the vehicle parent
	virtual Van* clone() const;

	//override the getType function from the vehicle parent
	virtual std::string getType() const;
	//override the getRefuelTime function from the vehicle parent
	virtual double getRefuelTime() const;

	//override the toString function from the vehicle parent
	virtual std::string toString() const override;


};



#endif /* SRC_VAN_H_ */
