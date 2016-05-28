/*
 * Vehicle.h
 *
 *  Created on: 21/04/2016
 *      Author: Sérgio
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <vector>
#include "User.h"

using namespace std;

class Vehicle
{
	int iddriver;
	int seats;
	double maxDev;
	int tolDep;
	int tolArr;
	vector<User*> passengers;
public:
	Vehicle(int u, int s, double md, int td, int ta);
	int getDriver();
	int getSeats();
	vector <User*> getPassengers();
	int getTolD() const;
	int getTolA() const;
	double getMaxDev() const;
	void setSeats();
	void addPass(User * u);
};



#endif /* VEHICLE_H_ */
