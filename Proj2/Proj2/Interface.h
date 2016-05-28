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
#include <sstream>
#include "Graph.h"
#include "Auxiliar.h"
#include "GraphViewer.h"

#ifndef INTERFACE_H_
#define INTERFACE_H_


#define TAB    "   "

void readCoords(Graph &g);
void readRoadName(vector <Road *> &estradas);
void readRoadConnect(Graph &g,vector <Road *> &estradas);
void readUsers(Graph &g);
void readVehicles(Graph &g);
void drawGraph(GraphViewer * gv,Graph &g,vector<vector<Vertex*> > &todasAsRotas);
vector <vector<long long> > groupCalc(Graph &g,vector<vector<Vertex*> > &todasAsRotas);
int findLonLong(vector<long long> v, long long a);
bool findVertex1(Graph &g,vector <Vertex *> path,Vertex* v);
void writeRoutes(vector<vector<Vertex*> > &v, vector<vector<Road*> > & v1);
void writePassengers(vector<Vehicle*> v);
void pre_kmp(string pattern, vector<int> & prefix);
int kmp(string text, string pattern);
int numStringMatchingRuas(string filename,string toSearch, vector<int> &v);
int numStringMatchingUsers(string filename,string toSearch, vector<int> &v);
void showRoutes(vector <int> ids, vector<vector<Road*> > & v2);
void showVehicle(vector <int> ids1, vector<Vehicle*> &v3);
int editDistance(string pattern, string text);
float numApproximateStringMatching(string filename,string toSearch);
struct vertex_lower_than
{
	bool operator()(Vertex * a, Vertex * b) const
	{
		return a->getDist() < b->getDist();
	}
};

#endif /* INTERFACE_H_ */
