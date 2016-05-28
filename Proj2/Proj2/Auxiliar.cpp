/*
 * Auxiliar.cpp
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#include "Auxiliar.h"
/**
 * Calculates the distance between 2 points.
 *
 * @param lat1 the latitude in radians of the first point
 * @param lat2 the latitude in radians of the second point
 * @param long1 the longitude in radians of the first point
 * @param long2 the longitude in radians of the second point
 * @return the distance
 */
double coordsToDistanceRad(double lat1, double lat2, double long1, double long2)
{
	double u = sin((lat2-lat1)/2);
	double v = sin((long2-long1)/2);

	return 2 * 6371 * asin(sqrt(u*u+cos(lat1)*cos(lat2)*v*v));
}

/**
 * Converts values in degrees to radians.
 *
 * @param deg value in degrees
 * @return the conversion
 *
 */
double deg2rad(double deg)
{
	return deg*M_PI/180;
}
/**
 * Calculates the distance between 2 points.
 *
 * @param lat1 the latitude in degrees of the first point
 * @param lat2 the latitude in degrees of the second point
 * @param long1 the longitude in degrees of the first point
 * @param long2 the longitude in degrees of the second point
 * @return the distance
 */
double coordsToDistanceDeg(double lat1, double lat2, double long1, double long2)
{

	double lat1r= deg2rad(lat1);
	double long1r=deg2rad(long1);
	double lat2r = deg2rad(lat2);
	double long2r = deg2rad(long2);
	double u = sin((lat2r-lat1r)/2);
	double v = sin((long2r-long1r)/2);

	return 2 * 6371 * asin(sqrt(u*u+cos(lat1r)*cos(lat2r)*v*v));

}
/**
 *Calculates de difference between 2 times.
 *
 *@param h1 the first value
 *@param h2 the second value
 *@return the difference between times
 */
int deltaTime(int h1,int h2)
{
	return h1-h2;
}

