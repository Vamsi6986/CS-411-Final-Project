/*File Name: Minivan.h
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#ifndef SRC_MINIVAN_H_
#define SRC_MINIVAN_H_

#include <string>
#include "Vehicle.h"

class Minivan : public Vehicle {
public:
	//default constructor
	Minivan();

	//custom constructor
	Minivan(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway);

	//overriding clone function within vehicle class
	virtual Minivan* clone() const;

	//overriding getType function within vehicle class
	virtual std::string getType() const;

	//overriding getRefuelTime function within vehicle class
	virtual double getRefuelTime() const;

	//overriding toString function within vehicle class
	virtual std::string toString() const override;

};




#endif /* SRC_MINIVAN_H_ */
