/*
 * Vertex.h
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <vector>
#include "Graph.h"
#include "Edge.h"

class Edge;

using namespace std;

class Vertex
{
	double node_id;
	double lat_g;
	double lon_g;
	double lat_r;
	double lon_r;
	vector<Edge*> adj;
	bool visited;
	bool processing;
	int indegree;
	double dist;
public:
	Vertex(long long n, double lg, double lng, double lr, double lnr);
	friend class Graph;
	long long getNode();
	double getLatG();
	double getLonG();
	double getLatR();
	double getLonR();
	double getDist();
	vector<Edge*> getEdgesAdj();
	Vertex * path;
	void addEdgeAdj(Edge* a);
	bool getVisited();

};


#endif /* VERTEX_H_ */
