/*
 * Graph.cpp
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#include "Graph.h"
/**
 * Adds 1 Vertex to the vector of Vertexs.
 *
 * @param a the Vertex
 */
void Graph::addVertex(Vertex * a)
{
	vertex.push_back(a);
}
/**
 * Gets the Vertexs.
 *
 * @return the vector of Vertexs
 */
vector<Vertex*> Graph::getVertexs() const
{
	return vertex;
}
/**
 * Gets the Users.
 *
 * @return the vector of Users
 */
vector<User*> Graph::getUsers() const
{
	return users;
}
/**
 * Adds 1 user to the vector of Users.
 *
 * @param u the User
 */
void Graph::addUser(User *u)
{
	users.push_back(u);
}
/**
 * Gets the Vertex with the specified ID.
 *
 * @param id the Vertex ID
 * @return the Vertex
 */
Vertex* Graph::getVertex(int id) const
{
	for(unsigned int i = 0; i < vertex.size(); i++)
		if (vertex[i]->node_id == id) return vertex[i];
	return NULL;
}

/**
 * A structure to represent a comparison of distances between 2 Vertexs.
 */
struct vertex_greater_than
{
	bool operator()(Vertex * a, Vertex * b) const
	{
		return a->getDist() > b->getDist();
	}
};

/**
 * Dijkstra algorithm to calculate the shortest path.
 *
 * @param id the ID of the origin Vertex
 */
void Graph::dijkstraShortestPath(long long id)
{

	for(unsigned int i = 0; i < vertex.size(); i++) {
		vertex[i]->path = NULL;
		vertex[i]->dist = INT_INFINITY;
		vertex[i]->processing = false;
	}

	Vertex* v = getVertex(id);
	v->dist = 0;

	vector< Vertex* > pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();
		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex* w = v->adj[i]->dest;
			if(v->dist + v->adj[i]->getDist() < w->dist ) {

				w->dist = v->dist + v->adj[i]->getDist();
				w->path = v;

				//se já estiver na lista, apenas a actualiza
				if(!w->processing)
				{
					w->processing = true;
					pq.push_back(w);
				}

				make_heap(pq.begin(),pq.end(),vertex_greater_than());
			}
		}
	}
}

/**
 * Adds 1 vehicle to the vector of Vehicles.
 *
 * @param v the Vehicle
 */
void Graph::addVehicle(Vehicle * v)
{
	vehicles.push_back(v);
}

/**
 * Gets the Vehicles.
 *
 * @return the vector of Vehicles
 */
vector<Vehicle*> Graph::getVehicles() const
{
	return vehicles;
}
/**
 * Gets the Roads.
 *
 * @returns the vector of Roads
 */
vector<Road *> Graph::getRoads() const
{
	return roads;
}

/**
 * Adds 1 Road to the vector of Roads.
 *
 * @param r the Road
 */
void Graph::addRoad(Road * r)
{
	roads.push_back(r);
}
/**
 * Gets the User with the specified ID.
 *
 * @param id the ID of the User
 * @return the User
 */
User * Graph::getUser(int id)
{
	User * u;
	for (unsigned int i=0; i < users.size(); i++)
	{
		if (users.at(i)->getUserId()== id)
		{
			u =users.at(i);
			break;
		}
	}

	return u;
}
/**
 * Sets a different Id to each Edge
 */
void Graph::setEdgesID()
{
	int x=0;
	for(unsigned int i=0;i < getVertexs().size();i++)
	{
		for(unsigned int j=0;j < getVertexs().at(i)->getEdgesAdj().size();j++)
		{
			getVertexs().at(i)->getEdgesAdj().at(j)->setId(x);
			x++;
		}
	}
}

/**
 * Checks which Users don't have a Vehicle and puts them in a vector.
 *
 * @return the vector of Users
 */
vector<User *> Graph::saveWithoutVehicle()
{
	vector<User*> withoutVehicle;

	for(unsigned int i = 0; i < getUsers().size(); i++)
	{
		if(getUsers().at(i)->getHasVehicle() == false)
		{
			withoutVehicle.push_back(getUsers().at(i));
		}
	}

	return withoutVehicle;
}

/**
 * Gets the departure time in minutes of a specific User.
 *
 * @param u the User
 * @return the departure time
 */
int Graph::getDep(User * u)
{
	return (u->getDepartureH()*60 + u->getDepartureM());
}
/**
 * Gets the arrival time in minutes of a specific User.
 *
 * @param u the User
 * @return the arrival time
 */
int Graph::getArr(User * u)
{
	return (u->getArrivalH()*60 + u->getArrivalM());
}
/**
 * Gets the Adress of the origin of a User.
 *
 * @param u the User
 * @return the adress
 */
string Graph::getAdressOri(User * u)
{
	return u->getAddress();
}

/**
 * Gets the Adress of the destination of a User.
 *
 * @param u the User
 * @return the adress
 */
string Graph::getAdressDest(User *u)
{
	return u->getDest();
}
/**
 * Gets the Road of the specified name.
 *
 * @param s the name of the Road
 * @return the Road
 */
Road * Graph::getRoad(string s)
{
	Road * r;
	for (unsigned int i=0; i < getRoads().size(); i++)
	{
		if (s.compare(getRoads().at(i)->getName())== 0)
		{
			r = getRoads().at(i);
			break;
		}
	}

	return r;
}
/**
 * Gets the Vertex of the specified Road.
 *
 * @param r the Road
 * @return the Vertex
 */
Vertex * Graph::getVertexR(Road * r)
{
	Vertex * v;
	for(unsigned int i = 0; i < getVertexs().size(); i++)
	{
		for(unsigned int j = 0; j < getVertexs().at(i)->getEdgesAdj().size(); j++)
		{
			if(r->getRoadId()== getVertexs().at(i)->getEdgesAdj().at(j)->getRoad()->getRoadId())
			{
				v= getVertexs().at(i);
				break;
			}
		}
	}

	return v;
}

/**
 * Gets the vector of Vertexs between 2 Vertexs.
 *
 * @param origin the origin Vertex
 * @param dest the destination Vertex
 * @return the vector of Vertexs between the 2 Vertexs given
 */
vector<Vertex *> Graph::getPath( Vertex * &origin, Vertex * &dest)
{
	list<Vertex *> buffer;
	Vertex * v = dest;

	buffer.push_front(v);

	while ( v->path != NULL &&  v->path != origin)
	{
		v = v->path;
		buffer.push_front(v);
	}

	if( v->path != NULL )
		buffer.push_front(v->path);

	vector<Vertex *> res;

	while( !buffer.empty() )
	{
		res.push_back( buffer.front() );
		buffer.pop_front();
	}
	return res;
}
/**
 * Bfs algorithm, checks the connectivity from a Vertex to the others.
 *
 * @param v the origin Vertex
 * @return the vector of IDs of the Vertexs reached by v
 */
vector<long long> Graph::bfs(Vertex *v) const
{
	for (unsigned int t=0; t < getVertexs().size(); t++)
	{
		getVertexs().at(t)->visited = false;
	}

	queue < Vertex *> q;
	vector <long long> res;
	q.push(v);
	v->visited=true;

	while(!q.empty())
	{
		Vertex *v1 = q.front();
		res.push_back(v1->getNode());
		q.pop();

		for (unsigned int i=0; i < v1->getEdgesAdj().size(); i++)
		{
			Vertex * d = v1->getEdgesAdj().at(i)->getDest();

			if(d->visited == false)
			{
				d->visited = true;
				q.push(d);
			}

		}
	}
	return res;
}

/**
 * Searches a Vertex in a vector of Vertexs IDs.
 *
 * @param v the vector of Vertexs IDs
 * @param p the Vertex
 * @return true if the ID of the Vertex is found in the vector of IDs, otherwise false
 */
bool Graph::searchUser(vector <long long> v, Vertex * p)
{
	bool ok=false;

	for (unsigned int i=0; i < v.size(); i++)
	{
		if(v.at(i)== p->getNode())
		{
			ok =true;
		}
	}

	return ok;
}


/**
 * Calculates getPath for each Vertex of the vector.
 *
 * @param perc the Vertex
 * @return the vector of Vertexs with the semipaths
 */
vector<Vertex*> Graph::calcPath(vector<Vertex*> perc)
{
	vector<Vertex*> pathOfTravel;
	for(unsigned int i = 0; i < perc.size() - 1; i++)
	{
		vector<Vertex*> semiPath;
		semiPath = getPath(perc.at(i), perc.at(i+1));
		for(unsigned int j = 0; j < semiPath.size(); j++)
		{
			pathOfTravel.push_back(semiPath.at(j));
		}
	}
	return pathOfTravel;

}


