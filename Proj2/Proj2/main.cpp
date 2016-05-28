#include "Interface.h"

int main()
{
	Graph g;
	vector<Road*> estradas;
	GraphViewer *gv = new GraphViewer(600, 600,false);
	vector<vector<Vertex*> > todasAsRotas;

	readCoords(g);
	readRoadName(estradas);
	readRoadConnect(g,estradas);
	readUsers(g);
	readVehicles(g);
	g.setEdgesID();
	drawGraph(gv,g,todasAsRotas);
	showRoutes(todasAsRotas);
}




















