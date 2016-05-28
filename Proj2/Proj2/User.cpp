/*
 * User.cpp

*/
#include "User.h"
using namespace std;

/**
 * Constructor of User.
 *
 * @param id the User Id
 * @param nome the User name
 * @param adr the User address
 * @param d the User destination
 * @param deph the User departure hour
 * @param depm the User departure minute
 * @param arrh the User arrival hour
 * @param arrm the User arrival minute
 * @param v wether the User has a vehicle or not
 */

User::User(int id, string nome, string adr, string d, int deph, int depm, int arrh, int arrm, bool v):
				user_id(id), name(nome), address(adr), dest(d), arrivalh(arrh), arrivalm(arrm), departureh(deph), departurem(depm), hasVehicle(v){}

/**
 * Gets the User ID.
 *
 * @return the value of the User's ID
 */
int User::getUserId()
{
	return user_id;
}
/**
 * Gets the address.
 *
 * @return the User's adress
 */
string User::getAddress()
{
	return address;
}
/**
 * Gets the destination.
 *
 * @return the destinaton of the User
 */
string User::getDest()
{
	return dest;
}
/**
 * Gets arrival hour.
 *
 *@return the arrival hour of the User
 */
int User::getArrivalH()
{
	return arrivalh;
}
/**
 *Gets the arrival minute.
 *
 *@return the arrival minute of the User
 */
int User::getArrivalM()
{
	return arrivalm;
}
/**
 * Gets departure hour.
 *
 *@return the departure hour of the User
 */
int User::getDepartureH()
{
	return departureh;
}
/**
 * Gets departure minute.
 *
 *@return the departure minute of the User
 */
int User::getDepartureM()
{
	return departurem;
}

/**
 * Gets wether the User has a Vehicle or not.
 *
 * @return true, if the User has a Vehicle, otherwise false
 */
bool User::getHasVehicle()
{
	return hasVehicle;
}


