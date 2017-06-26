//WichitaToMonticello.cpp
//Author: Dakota Swanson
//Student ID: *****
//Assignment Number: 4

#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Vehicle.h"
#include "VehicleTrip.h"
#include "TripLeg.h"
#include "TripParameters.h"
#include "VehicleRecords.h"

using namespace std;

static const int debug = 0;


static const char FILENAME_INPUT[] = "WichitaToMonticello-Input.ini";
static const char FILENAME_RESULTS[] = "WichitaToMonticello-Results2.txt";
static const char FILENAME_VEHICLES[] = "WichitaToMonticello-Vehicles2.txt";

static void outputTripDistance(ostream &fout, const Trip &trip)
{
	char str[100];

	sprintf(str, "Total trip distance: %.2f (city: %.2f, highway: %.2f)",
			trip.getTotalDistance(), trip.getCityDistance(), trip.getHighwayDistance());

	fout << endl << str << endl;
}

static void outputVehicleTripObjective(ostream &fout, const char objective[], const VehicleTrip &vehicleTrip)
{
	fout << endl << objective << ":" << endl << vehicleTrip << endl;
}


static void outputVehicleArrivingFirst(ostream &fout, const VehicleTrip &vehicleTrip)
{
	outputVehicleTripObjective(fout, "Vehicle arriving first", vehicleTrip);
}


static void outputVehicleArrivingLast(ostream &fout, const VehicleTrip &vehicleTrip)
{
	outputVehicleTripObjective(fout, "Vehicle arriving last", vehicleTrip);
}


static void outputVehicleCostingLeastFuelAdded(ostream &fout, const VehicleTrip &vehicleTrip)
{
	outputVehicleTripObjective(fout, "Vehicle costing least (based on fuel added)", vehicleTrip);
}


static void outputVehicleCostingMostFuelAdded(ostream &fout, const VehicleTrip &vehicleTrip)
{
	outputVehicleTripObjective(fout, "Vehicle costing most (based on fuel added)", vehicleTrip);
}


static void outputVehicleCostingLeastFuelUsed(ostream &fout, const VehicleTrip &vehicleTrip)
{
	outputVehicleTripObjective(fout, "Vehicle costing least (based on fuel used)", vehicleTrip);
}


static void outputVehicleCostingMostFuelUsed(ostream &fout, const VehicleTrip &vehicleTrip)
{
	outputVehicleTripObjective(fout, "Vehicle costing most (based on fuel used)", vehicleTrip);
}


static void storeVehicle(ofstream &file, const VehicleTrip &vehicleTrip) {
	static bool needHeader = true;

	if (needHeader) {
		needHeader = false;
		file << VehicleRecords::formatHeaderForFile() << endl;
	}
	file << VehicleRecords::formatRecordForFile(vehicleTrip) << endl;
}


static void storeVehicleTripObjective(ofstream &file, const string &objective, const VehicleTrip &vehicleTrip) {
	static bool needLineSeparator = true;

	if (needLineSeparator) {
		needLineSeparator = false;
		file << endl;
	}
	file << (VehicleRecords::formatRecordForFile(vehicleTrip) + " # " + objective) << endl;
}


static void storeVehicleArrivingFirst(ofstream &file, const VehicleTrip &vehicleTrip) {
	storeVehicleTripObjective(file, "Vehicle arriving first", vehicleTrip);
}



static void storeVehicleArrivingLast(ofstream &file, const VehicleTrip &vehicleTrip) {
	storeVehicleTripObjective(file, "Vehicle arriving last", vehicleTrip);
}


static void storeVehicleCostingLeastFuelAdded(ofstream &file, const VehicleTrip &vehicleTrip) {
	storeVehicleTripObjective(file, "Vehicle costing least (fuel added)", vehicleTrip);
}


static void storeVehicleCostingMostFuelAdded(ofstream &file, const VehicleTrip &vehicleTrip) {
	storeVehicleTripObjective(file, "Vehicle costing most (fuel added)", vehicleTrip);
}


static void storeVehicleCostingLeastFuelUsed(ofstream &file, const VehicleTrip &vehicleTrip) {
	storeVehicleTripObjective(file, "Vehicle costing least (fuel used)", vehicleTrip);
}


static void storeVehicleCostingMostFuelUsed(ofstream &file, const VehicleTrip &vehicleTrip) {
	storeVehicleTripObjective(file, "Vehicle costing most (fuel used)", vehicleTrip);
}



int main()
{
	TripParameters tripParameters;
	try {
		tripParameters = TripParameters(FILENAME_INPUT);
	} catch (const ifstream::failure &e) {
		cout << "Unable to open trip parameters file" << e.what() << endl;
		cout << "Program ending!" << endl;
		exit(1);
	} catch (const invalid_argument &e) {
		cout << e.what() << endl;
		cout << "Program ending!" << endl;
		exit(1);
	} catch (const out_of_range &e) {
		cout << e.what() << endl;
		cout << "Program ending!" << endl;
		exit(1);
	}


	if (debug) {
		cout << "Average speed in the city (MPH): " << tripParameters.getMphCity() << endl;
		cout << "Average speed on the highway (MPH): " << tripParameters.getMphHighway() << endl;
		cout << "Average fuel price per gallon: " << tripParameters.getFuelPrice() << endl;
		cout << "Distance between gas stations (miles): " << tripParameters.getDistanceBetweenGasStations() << endl;
		cout << "Time between taking naps (hours): " << tripParameters.getTimeBetweenNaps() << endl;
	//	cout << "Time required to refuel (minutes): " << tripParameters.getRefuelTime() << endl;	not required for this assignment
		cout << "Time required to use the restroom (minutes): " << tripParameters.getRestroomTime() << endl;
		cout << "Time required to take a nap (minutes): " << tripParameters.getNapTime() << endl;

	}


	Trip trip;

	vector<Vehicle *> vehicles;
	try {
		vehicles = VehicleRecords::getVehicles(FILENAME_VEHICLES);
	} catch (const ifstream::failure &e) {
		cout << "Unable to open vehicle records file" << e.what() << endl;
		cout << "Program ending!" << endl;
		exit(1);
	} catch (const invalid_argument &e) {
		cout << e.what() << endl;
		cout << "Program ending!" << endl;
		exit(1);
	}


	ofstream file;
	file.open(FILENAME_RESULTS);
	if (file.fail()) {
		cout << "Unable to open vehicle results file" << endl;
		cout << "Program ending!" << endl;
		exit(1);
	}

	VehicleTrip minVehicleTripTime;
	VehicleTrip maxVehicleTripTime;
	VehicleTrip minVehicleTripCostFuelAdded;
	VehicleTrip maxVehicleTripCostFuelAdded;
	VehicleTrip minVehicleTripCostFuelUsed;
	VehicleTrip maxVehicleTripCostFuelUsed;

	vector<VehicleTrip> vehicleTrips;


	for (int i = 0; i < (int) vehicles.size(); i++) {
			VehicleTrip vehicleTrip(vehicles[i], trip, tripParameters);

			vehicleTrips.push_back(vehicleTrip);

			// Determine if this vehicle satisfies one (or more) of the objectives
			if (minVehicleTripTime.isTimeMoreThan(vehicleTrip))
				minVehicleTripTime = vehicleTrip;
			if (maxVehicleTripTime.isTimeLessThan(vehicleTrip))
				maxVehicleTripTime = vehicleTrip;
			if (minVehicleTripCostFuelAdded.isFuelAddedCostMoreThan(vehicleTrip))
				minVehicleTripCostFuelAdded = vehicleTrip;
			if (maxVehicleTripCostFuelAdded.isFuelAddedCostLessThan(vehicleTrip))
				maxVehicleTripCostFuelAdded = vehicleTrip;
			if (minVehicleTripCostFuelUsed.isFuelUsedCostMoreThan(vehicleTrip))
				minVehicleTripCostFuelUsed = vehicleTrip;
			if (maxVehicleTripCostFuelUsed.isFuelUsedCostLessThan(vehicleTrip))
				maxVehicleTripCostFuelUsed = vehicleTrip;

			// Output debug information for each vehicle trip
			if (debug)
				cout << endl << vehicleTrip << endl;

		}

	//calls the sort method, this will put the vehicleTrips in order
	sort(vehicleTrips.begin(), vehicleTrips.end(), VehicleTrip::compare);

	//stores the vehicleTrips
	for(int i = 0; i < (int) vehicleTrips.size(); i++) {
		storeVehicle(file, vehicleTrips[i]);
	}



		// Output results
		outputTripDistance(cout, trip);
		outputVehicleArrivingFirst(cout, minVehicleTripTime);
		outputVehicleArrivingLast(cout, maxVehicleTripTime);
		outputVehicleCostingLeastFuelAdded(cout, minVehicleTripCostFuelAdded);
		outputVehicleCostingMostFuelAdded(cout, maxVehicleTripCostFuelAdded);
		outputVehicleCostingLeastFuelUsed(cout, minVehicleTripCostFuelUsed);
		outputVehicleCostingMostFuelUsed(cout, maxVehicleTripCostFuelUsed);

		// Store results in file
		storeVehicleArrivingFirst(file, minVehicleTripTime);
		storeVehicleArrivingLast(file, maxVehicleTripTime);
		storeVehicleCostingLeastFuelAdded(file, minVehicleTripCostFuelAdded);
		storeVehicleCostingMostFuelAdded(file, maxVehicleTripCostFuelAdded);
		storeVehicleCostingLeastFuelUsed(file, minVehicleTripCostFuelUsed);
		storeVehicleCostingMostFuelUsed(file, maxVehicleTripCostFuelUsed);

		// Close file for storing results
		file.close();
	}
