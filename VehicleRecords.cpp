/*File Name: VehicleRecords.cpp
 *Author: Dakota Swanson
 *Student ID: P853E744
 *Assignment Number: 4
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstddef>
#include <vector>

#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Minivan.h"
#include "Truck.h"
#include "Suv.h"
#include "StringEnh.h"
#include "VehicleRecords.h"


ifstream fin;

static std::string RECORD_DELIMITER = "|";

static Vehicle* deserialize(std::string recordString) throw (std::invalid_argument, std::out_of_range)
{
	// Transform vehicle record from a string to a tokenized string (vector of strings)
	std::vector<std::string> record = StringEnh::tokenize(recordString, RECORD_DELIMITER);

	// Validate vehicle record includes required sub-components, cannot continue if not
	if (record.size() != 8)
		throw std::invalid_argument("Improper syntax for vehicle record (" + recordString + ")");

	// Start with first item
	int fieldIndex = 0;

	//read in type from vehicle record
	std::string type = StringEnh::trim(record[fieldIndex++]);

	// Parse make from vehicle record
	std::string make = StringEnh::trim(record[fieldIndex++]);
	if (make.empty())
		throw std::out_of_range("Make was not detected in vehicle record (" + recordString + ")");

	// Parse model from vehicle record
	std::string model = StringEnh::trim(record[fieldIndex++]);
	if (model.empty())
		throw std::out_of_range("Model was not detected in vehicle record (" + recordString + ")");

	// Parse engine size from vehicle record
	std::string tempEngineSize = StringEnh::trim(record[fieldIndex++]);
	if (tempEngineSize.empty())
		throw std::out_of_range("Engine size was not detected in vehicle record (" + recordString + ")");

	// Convert engine size from string to double
	double engineSize = 0.0;
	try {
		engineSize = std::stod(tempEngineSize);
	} catch (const std::invalid_argument &e) {
		throw std::out_of_range("Engine size is invalid in vehicle record (" + recordString + ")");
	} catch (const std::out_of_range &e) {
		throw std::out_of_range("Engine size is invalid in vehicle record (" + recordString + ")");
	}

	// Parse engine number of cylinders from vehicle record
	std::string tempEngineCylinders = StringEnh::trim(record[fieldIndex++]);
	if (tempEngineCylinders.empty())
		throw std::out_of_range("Engine cylinders was not detected in vehicle record (" + recordString + ")");

	// Convert engine number of cylinders from string to int
	int engineCylinders = 0;
	try {
		engineCylinders = std::stoi(tempEngineCylinders);
	} catch (const std::invalid_argument &e) {
		throw std::out_of_range("Engine cylinders is invalid in vehicle record (" + recordString + ")");
	} catch (const std::out_of_range &e) {
		throw std::out_of_range("Engine cylinders is invalid in vehicle record (" + recordString + ")");
	}

	// Parse tank size from vehicle record
	std::string tempTankSize = StringEnh::trim(record[fieldIndex++]);
	if (tempTankSize.empty())
		throw std::out_of_range("Tank size was not detected in vehicle record (" + recordString + ")");

	// Convert tank size from string to double
	double tankSize = 0.0;
	try {
		tankSize = std::stod(tempTankSize);
	} catch (const std::invalid_argument &e) {
		throw std::out_of_range("Tank size is invalid in vehicle record (" + recordString + ")");
	} catch (const std::out_of_range &e) {
		throw std::out_of_range("Tank size is invalid in vehicle record (" + recordString + ")");
	}

	// Parse MPH in the city from vehicle record
	std::string tempMphCity = StringEnh::trim(record[fieldIndex++]);
	if (tempMphCity.empty())
		throw std::out_of_range("MPG in the city was not detected in vehicle record (" + recordString + ")");

	// Convert MPH in the city from string to int
	int mphCity = 0;
	try {
		mphCity = std::stoi(tempMphCity);
	} catch (const std::invalid_argument &e) {
		throw std::out_of_range("MPG in the city is invalid in vehicle record (" + recordString + ")");
	} catch (const std::out_of_range &e) {
		throw std::out_of_range("MPG in the city is invalid in vehicle record (" + recordString + ")");
	}

	// Parse MPH on the highway from vehicle record
	std::string tempMphHighway = StringEnh::trim(record[fieldIndex++]);
	if (tempMphHighway.empty())
		throw std::out_of_range("MPG on the highway was not detected in vehicle record (" + recordString + ")");

	// Convert MPH on the highway from string to int
	int mphHighway = 0;
	try {
		mphHighway = std::stoi(tempMphHighway);
	} catch (const std::invalid_argument &e) {
		throw std::out_of_range("MPG on the highway is invalid in vehicle record (" + recordString + ")");
	} catch (const std::out_of_range &e) {
		throw std::out_of_range("MPG on the highway is invalid in vehicle record (" + recordString + ")");
	}

	// Return vehicle

	if(type == "Car")
		return new Car(make, model, engineSize, engineCylinders, tankSize, mphCity, mphHighway);
	if(type == "Suv")
		return new Suv(make, model, engineSize, engineCylinders, tankSize, mphCity, mphHighway);
	if(type == "Van")
		return new Van(make, model, engineSize, engineCylinders, tankSize, mphCity, mphHighway);
	if(type == "Minivan")
		return new Minivan(make, model, engineSize, engineCylinders, tankSize, mphCity, mphHighway);
	if(type == "Truck")
		return new Truck(make, model, engineSize, engineCylinders, tankSize, mphCity, mphHighway);

	throw std::out_of_range("Type was not detected in vehicle record (" + recordString + ")");
}


VehicleRecords::VehicleRecords()
{
}


std::vector<Vehicle *> VehicleRecords::getVehicles(const char filename[]) throw (std::ifstream::failure, std::invalid_argument, std::out_of_range)
{
	std::vector<Vehicle *> vehicles;
	std::ifstream ifs;

	// Enable throwing of fail and bad exceptions
	ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	// Open file containing vehicles
	ifs.open(filename);

	// Enable throwing of bad exceptions (when eofbit is set, failbit may also be set)
	ifs.exceptions(std::ifstream::badbit);

	// Repeat while lines still exist
	while (ifs.peek() != EOF) {
		// Read a line from the file
		std::string recordString;
		getline(ifs, recordString);

		// Determine if line is a comment, blank line, or a vehicle record
		recordString = StringEnh::trim(recordString);
		if (!recordString.empty() && recordString[0] != '#') {
			// Deserialize vehicle record from a string to a class and store in list
			vehicles.push_back(deserialize(recordString));
		}
	}

	// Close file
	ifs.close();

	// Return list of vehicles
	return vehicles;
}


std::string VehicleRecords::formatHeaderForFile() {
	std::string headerString =
		std::string("Type") + RECORD_DELIMITER +
		std::string("Make") + RECORD_DELIMITER +
		std::string("Model") + RECORD_DELIMITER +
		std::string("EngineSize") + RECORD_DELIMITER +
		std::string("EngineCylinders") + RECORD_DELIMITER +
		std::string("TankSize") + RECORD_DELIMITER +
		std::string("MpgCity") + RECORD_DELIMITER +
		std::string("MpgHighway") + RECORD_DELIMITER +
		std::string("Time(minutes)") + RECORD_DELIMITER +
		std::string("Time(d.hh:mm)") + RECORD_DELIMITER +
		std::string("CostFuelAdded") + RECORD_DELIMITER +
		std::string("CostFuelUsed") + RECORD_DELIMITER +
		std::string("FuelAdded") + RECORD_DELIMITER +
		std::string("FuelUsed") + RECORD_DELIMITER +
		std::string("FuelRemaining") + RECORD_DELIMITER +
		std::string("FuelStops");

	// Return vehicle trip header as a string for storing in a file
	return headerString;
}

/**
 * Format vehicle trip data record as a string for storing in a file
 */
std::string VehicleRecords::formatRecordForFile(const VehicleTrip &vehicleTrip) {
	char str[400];
	const std::string formatString =
		std::string("%s") + RECORD_DELIMITER +
		std::string("%s") + RECORD_DELIMITER +
		std::string("%s") + RECORD_DELIMITER +
		std::string("%.1f") + RECORD_DELIMITER +
		std::string("%d") + RECORD_DELIMITER +
		std::string("%.1f") + RECORD_DELIMITER +
		std::string("%d") + RECORD_DELIMITER +
		std::string("%d") + RECORD_DELIMITER +
		std::string("%d") + RECORD_DELIMITER +
		std::string("%d.%02d:%02d") + RECORD_DELIMITER +
		std::string("%.2f") + RECORD_DELIMITER +
		std::string("%.2f") + RECORD_DELIMITER +
		std::string("%.4f") + RECORD_DELIMITER +
		std::string("%.4f") + RECORD_DELIMITER +
		std::string("%.4f") + RECORD_DELIMITER +
		std::string("%d");

	Vehicle* vehicle = vehicleTrip.getVehicle();

	sprintf(str, formatString.c_str(), vehicle->getType().c_str(),
		vehicle->getMake().c_str(), vehicle->getModel().c_str(),
		vehicle->getEngineSize(), vehicle->getEngineCylinders(),
		vehicle->getTankSize(), vehicle->getMpgCity(), vehicle->getMpgHighway(),
		(int) vehicleTrip.getTime(), vehicleTrip.getTimeNumDays(), vehicleTrip.getTimeNumHours(), vehicleTrip.getTimeNumMinutes(), vehicleTrip.getFuelAddedCost(), vehicleTrip.getFuelUsedCost(),
		vehicleTrip.getFuelAdded(), vehicleTrip.getFuelUsed(), vehicleTrip.getFuelRemaining(), vehicleTrip.getFuelStops());

	delete vehicle;
	// Return vehicle trip data record as a string for storing in a file
	return std::string(str);
}
