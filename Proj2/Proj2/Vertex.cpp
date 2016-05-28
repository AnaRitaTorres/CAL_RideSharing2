/*
 * Vertex.cpp
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#include "Vertex.h"
/**
 * Constructor of Vertex.
 *
 * @param n the Vertex ID
 * @param lg the latitude in degrees
 * @param lng the longitude in degress
 * @param lr the latitude in radians
 * @param lnr the longitude in radians
 */
Vertex::Vertex(long long n, double lg,  double lng,  double lr, double lnr):
				node_id(n), lat_g(lg), lon_g(lng), lat_r(lr), lon_r(lnr){}

/**
 * Gets the latitude in degrees of the Vertex.
 *
 * @return the latitude in degrees
 */
double Vertex::getLatG()
{
	return lat_g;
}
/**
 * Gets the latitude in radians of the Vertex.
 *
 * @return the latitude in radians
 */
double Vertex::getLatR()
{
	return lat_r;
}
/**
 * Gets the longitude in degrees of the Vertex.
 *
 * @return the longitude in degrees
 */
double Vertex::getLonG()
{
	return lon_g;
}
/**
 * Gets the longitude in radians of the Vertex.
 *
 * @return the longitude in radians
 */
double Vertex::getLonR()
{
	return lon_r;
}
/**
 * Gets the Vertex's ID.
 *
 * @return the ID of the Vertex
 */
long long Vertex::getNode()
{
	return node_id;
}
/**
 * Gets the adjacent Edges of Vertex.
 *
 * @return the adjacent Edges of the Vertex
 */
vector<Edge*> Vertex::getEdgesAdj()
{
	return adj;
}
/**
 * Gets the distance of the Vertex.
 *
 * @return the distance of the Vertex
 */
double Vertex::getDist()
{
	return dist;
}
/**
 * Adds an Edge to the adjacent vector.
 *
 * @param a the adjacent Edge
 */
void Vertex::addEdgeAdj(Edge* a)
{
	adj.push_back(a);
}
/**
 * Checks wether the Vertex has been visited or not.
 *
 * @return true, if the Vertex has been visited, otherwise false
 */
bool Vertex::getVisited()
{
	return visited;
}
