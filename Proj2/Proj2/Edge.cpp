/*
 * Edge.cpp
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#include "Edge.h"

/**
 *Constructor of Edge.
 *
 *@param r Road
 *@param d Vertex Destination
 */
Edge::Edge(Road *r, Vertex *d):road(r), dest(d){}


/**
 * Sets the destination of the Edge.
 *
 * @param d Vertex Destination
 */
void Edge::setDest(Vertex* d)
{
	dest = d;
}

/**
 * Gets the destination.
 *
 * @return The destination of the Vertex of the Edge
 */
Vertex * Edge::getDest(){
	return dest;
}
/**
 * Gets the distance.
 *
 * @return the length of the Edge
 */
double Edge::getDist()const
{
	return dist;
}

/**
 * Sets the length of the Edge.
 *
 * @param d the length of the Edge
 */
void Edge::setDist(double d)
{
	dist=d;
}
/**
 * Gets the Road.
 *
 * @return the Road correspondent to the Edge
 */
Road * Edge::getRoad() const
{
	return road;
}

/**
 * Sets the Road correspondent to the Edge.
 *
 * @param r  the Road
 */
void Edge::setRoad(Road *r)
{
	road=r;
}
/**
 * Gets the ID of the Edge.
 *
 * @return the ID of the Edge
 */
int Edge::getId()
{
	return id;
}
/**
 * Sets ID of the Edge.
 *
 * @param i the ID
 */
void Edge::setId(int i)
{
	id=i;
}
