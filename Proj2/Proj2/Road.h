/*
 * Road.h
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#ifndef ROAD_H_
#define ROAD_H_

#include <string>
#include "Graph.h"
#include "Vertex.h"

using namespace std;

class Road
{
	string name;
	long long road_id;
	bool tw;
public:
	Road(string n, long long id, bool tways);
	Road(string n, bool tways);
	friend class Graph;
	friend class Vertex;
	string getName();
	long long getRoadId();
	bool getTw();
	void setTw(bool a);
};



#endif /* ROAD_H_ */
