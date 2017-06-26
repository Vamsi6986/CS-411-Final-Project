/*File Name: Truck.h
 * Author: Dakota Swanson
 * Student ID: P853E744
 * Assignment Number: 4
 */

#ifndef SRC_TRUCK_H_
#define SRC_TRUCK_H_

#include <string>
#include "Vehicle.h"


	class Truck : public Vehicle {
	public:
		//default constructor
		Truck();

		//custom constructor
		Truck(const std::string &make, const std::string &model, double engineSize, int engineCylinders, double tankSize, int mpgCity, int mpgHighway);

		//overriding clone function within vehicle class
		virtual Truck* clone() const;

		//overriding getType function within vehicle class
		virtual std::string getType() const;

		//overriding getRefuelTime function within vehicle class
		virtual double getRefuelTime() const;

		//overriding toString function within vehicle class
		virtual std::string toString() const override;

	};



#endif /* SRC_TRUCK_H_ */
