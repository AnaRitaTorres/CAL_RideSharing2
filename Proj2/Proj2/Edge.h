/*
 * Edge.h
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "Vertex.h"
#include "Road.h"

class Road;
class Vertex;

using namespace std;

class Edge
{
	Road * road;
	Vertex * dest;
	double dist;
	int id;
public:
	Edge(Road *r,Vertex *d);
	friend class Graph;
	friend class Vertex;
	double getDist() const;
	void setDest(Vertex* d);
	Vertex * getDest();
	void setDist(double d);
	Road * getRoad() const;
	void setRoad(Road * r);
	void setId(int i);
	int getId();

};


#endif /* EDGE_H_ */
