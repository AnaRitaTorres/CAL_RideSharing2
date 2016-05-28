/*
 * Auxiliar.h
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <math.h>


double coordsToDistanceRad(double lat1, double lat2, double long1, double long2);

double deg2rad(double deg);

double coordsToDistanceDeg(double lat1, double lat2, double long1, double long2);

int deltaTime(int h1, int h2);


#endif /* AUXILIAR_H_ */
