/*
 * Vehicle.cpp
 *
 *  Created on: 21/04/2016
 *      Author: Sérgio
 */
#include "Vehicle.h"


using namespace std;


/**
 * Constructor of Vehicle.
 *
 * @param u the Id of the driver
 * @param s the number of seats
 * @param md the maximal deviation of the route
 * @param td the tolerance of departure
 * @param ta the tolerance of arrival
 */
Vehicle::Vehicle(int u, int s, double md, int td, int ta):
				iddriver(u), seats(s), maxDev(md), tolDep(td), tolArr(ta)
{}

/**
 * Gets the driver's ID.
 *
 * @return the ID of the driver
 */
int Vehicle::getDriver()
{
	return iddriver;
}
/**
 * Gets the number of seats.
 *
 * @return the number of seats
 */
int Vehicle::getSeats()
{
	return seats;
}
/**
 * Gets the Passengers.
 *
 * @return the vector of Users without Vehicle(Passengers)
 */
vector <User*> Vehicle::getPassengers()
{
	return passengers;
}
/**
 * Gets departure tolerance.
 *
 * @return the departure tolerance
 */
int Vehicle::getTolD() const
{
	return tolDep;
}

/**
 * Gets arrival tolerance.
 *
 * @return the arrival tolerance
 */
int Vehicle::getTolA() const
{
	return tolArr;
}

/**
 * Gets Maximal deviation.
 *
 * @return the maximal deviation
 */
double Vehicle::getMaxDev() const
{
	return maxDev;
}

/**
 * Sets the number of Seats of the Vehicle.
 */
void Vehicle::setSeats()
{
	seats--;
}
/**
 * Adds passengers to a Vehicle
 *
 * @param the User
 */
void Vehicle::addPass(User * u)
{
	passengers.push_back(u);
}
