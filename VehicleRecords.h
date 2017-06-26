/*File Name: VehicleRecords.h
 * Author: Dakota Swanson
 * Student ID: *****
 * Assignment Number: 4
 */

#ifndef VEHICLE_RECORDS_H_
#define VEHICLE_RECORDS_H_

#include <fstream>
#include <stdexcept>
#include <vector>

#include "Vehicle.h"
#include "VehicleTrip.h"

class VehicleRecords
{
public:

	static std::vector<Vehicle *> getVehicles(const char filename[]) throw (std::ifstream::failure, std::invalid_argument, std::out_of_range);

	static std::string formatHeaderForFile();

	static std::string formatRecordForFile(const VehicleTrip &vehicleTrip);

private:

	VehicleRecords();

};

#endif /* SRC_VEHICLERECORDS_H_ */
