/*
 * Interface.h
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <algorithm>
#include <set>
#include "Graph.h"
#include "Auxiliar.h"
#include "GraphViewer.h"

#ifndef INTERFACE_H_
#define INTERFACE_H_

void readCoords(Graph &g);
void readRoadName(vector <Road *> &estradas);
void readRoadConnect(Graph &g,vector <Road *> &estradas);
void readUsers(Graph &g);
void readVehicles(Graph &g);
void drawGraph(GraphViewer * gv,Graph &g,vector<vector<Vertex*> > &todasAsRotas);
vector <vector<long long> > groupCalc(Graph &g,vector<vector<Vertex*> > &todasAsRotas);
int findLonLong(vector<long long> v, long long a);
bool findVertex1(Graph &g,vector <Vertex *> path,Vertex* v);
void showRoutes(vector<vector<Vertex*> > &v);
struct vertex_lower_than
{
	bool operator()(Vertex * a, Vertex * b) const
	{
		return a->getDist() < b->getDist();
	}
};

#endif /* INTERFACE_H_ */
