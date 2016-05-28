/*
 * Road.cpp
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#include "Road.h"
#include "Auxiliar.h"
/**
 * First constructor of Road.
 *
 * @param n the name
 * @param id the Road ID
 * @param tways the bool which states if a Road is two way or not
 */
Road::Road(string n, long long id, bool tways)
{
	name = n;
	tw = tways;
	road_id = id;
}
/**
 * Second constructor of Road.
 *
 * @param n the name
 * @param tways the bool which states if a Road is two way or not
 */
Road::Road(string n, bool tways)
{
	name = n;
	tw = tways;
}
/**
 * Gets the name of the Road.
 *
 * @return the name of the Road
 */

string Road::getName()
{
	return name;
}
/**
 * Gets the Road ID.
 *
 * @return the Id of the Road
 */
long long Road::getRoadId()
{
	return road_id;
}
/**
 * Gets the Tw.
 *
 * @return true, if a Road is two way , otherwise false
 */
bool Road::getTw()
{
	return tw;
}

/**
 * Sets Tw.
 *
 * @param a the Two Ways
 */
void Road::setTw(bool a)
{
	tw = a;
}






