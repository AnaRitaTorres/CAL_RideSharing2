/*
 * Graph.h
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <climits>
#include "Vertex.h"
#include "Vehicle.h"

using namespace std;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;

class Vertex;
class Road;

class Graph
{
	vector<Vertex *> vertex;
	vector<User *> users;
	vector<Vehicle *> vehicles;
	vector<Road *>roads;
public:
	void addVertex(Vertex * a);
	vector<Vertex*> getVertexs() const;
	vector<User*> getUsers() const;
	void addUser(User * u);
	Vertex* getVertex(int id) const;
	void dijkstraShortestPath(long long id);
	vector<Vertex*> dfs() const;
	void dfs(Vertex *v,vector<Vertex*> &res) const;
	void addVehicle(Vehicle * v);
	vector<Vehicle*> getVehicles() const;
	vector<Road *> getRoads() const;
	void addRoad(Road * r);
	User * getUser(int id);
	void setEdgesID();
	vector<User *> saveWithoutVehicle();
	int getDep(User * u);
	int getArr(User * u);
	string getAdressOri(User * u);
	string getAdressDest(User * u);
	Road * getRoad(string s);
	Vertex * getVertexR(Road * r);
	vector<Vertex *> getPath( Vertex * &origin, Vertex * &dest);
	vector<long long> bfs(Vertex *v) const;
	bool searchUser(vector <long long> v, Vertex * p);
	vector<Vertex*> calcPath(vector<Vertex*> perc);

};



#endif /* GRAPH_H_ */
