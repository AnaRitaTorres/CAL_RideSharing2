/*
 * Interface.cpp
 *
 *  Created on: 22/04/2016
 *      Author: Rita
 */

#include "Interface.h"
/**
 * Compares the distance between 2 Vertexs.
 * @param i the Vertex
 * @param j the Vertex
 */
bool myfunction(Vertex* i, Vertex* j)
{
	return (i->getDist() < j->getDist());
}

/**
 * Reads the coordinates from the file and saves coordinates in Vertexs.
 *
 * @param g the Graph
 */
void readCoords(Graph &g)
{
	ifstream f;
	string filename;

	/*do
	{
		cout << "Insira o ficheiro das coordenadas dos Vertices:";
		cin >> filename;
		f.open(filename.c_str());

	}while(f.fail());*/

	f.open("coordsVertex.txt");


	while(!f.eof())
	{
		string a, b, c, d, e;

		getline(f, a, ';');
		getline(f, b, ';');
		getline(f, c, ';');
		getline(f, d, ';');
		getline(f, e, '\n');
		long long node = atof(a.c_str());
		double lat_g = atof(b.c_str());
		double long_g = atof(c.c_str());
		double lat_r = atof(d.c_str());
		double long_r = atof(e.c_str());
		if(node == 0)
			break;
		Vertex *v1 = new Vertex(node, lat_g, long_g, lat_r, long_r);
		g.addVertex(v1);
	}
}

/**
 * Reads the information about roads from the file and saves Roads in the Roads vector.
 *
 * @param estradas the Roads vector
 */
void readRoadName(vector<Road *> &estradas)
{
	ifstream f;
	string filename;

	/*do
	{
		cout << "Insira o ficheiro com informações sobre as Ruas:";
		cin >> filename;
		//f.open(filename.c_str());

	}while(f.fail());*/

	f.open("roadName.txt");
	while(!f.eof())
	{
		string a, name, c;
		bool tw;

		getline(f, a, ';');
		getline(f, name, ';');
		getline(f, c, '\n');
		long long road = atoll(a.c_str());
		if (c == "False")
			tw = false;
		else
			tw = true;
		if(road == 0)
			break;
		Road *r = new Road(name, road, tw);
		estradas.push_back(r);
	}
}

/**
 * Reads the information about the Edges connections from the file and saves in the Roads vector.
 *
 * @param g1 the Graph
 * @param estradas the Roads vector
 */
void readRoadConnect(Graph &g1, vector<Road *> &estradas)
{
	Road * saveRoad;

	ifstream f;
	string filename;

	/*do
	{
		cout << "Insira o ficheiro com as ligacoes das Arestas:";
		cin >> filename;
		f.open(filename.c_str());

	}while(f.fail());*/

	f.open("edgeConnections.txt");
	while(!f.eof())
	{
		string a, b, c;

		getline(f, a, ';');
		getline(f, b, ';');
		getline(f, c, '\n');
		long long road = atoll(a.c_str());
		long long node1 = atoll(b.c_str());
		long long node2 = atoll(c.c_str());
		if(road == 0)
			break;


		for (unsigned int j=0; j < estradas.size(); j++)
		{
			if (estradas.at(j)->getRoadId()== road)
			{
				saveRoad= estradas.at(j);
			}
		}

		vector <Vertex*> v = g1.getVertexs();

		for (unsigned int i=0; i < v.size(); i++)
		{
			if (v.at(i)->getNode() == node1)
			{
				for (unsigned int h=0; h < v.size(); h++)
				{
					if(v.at(h)->getNode()== node2)
					{
						Edge *e1 = new Edge(saveRoad,v.at(h));
						e1->setDist(coordsToDistanceDeg(v.at(i)->getLatG(), v.at(h)->getLatG(),v.at(i)->getLonG(), v.at(h)->getLonG()));
						v.at(i)->addEdgeAdj(e1);

						if (saveRoad->getTw()== true)
						{
							Edge *e2 = new Edge(saveRoad,v.at(i));
							e2->setDist(e1->getDist());
							g1.getVertexs().at(h)->addEdgeAdj(e2);
						}
					}


				}
			}
		}

	}

	for(unsigned int k=0; k < estradas.size(); k++)
	{
		g1.addRoad(estradas.at(k));
	}
}
/**
 * Reads the informaton of the Users from the file and saves in the vector of Users.
 *
 * @param g1 the Graph
 */
void readUsers(Graph &g1)
{
	ifstream f;
	string filename;

	/*do
	{
		cout << "Insira o ficheiro com as informacoes dos Utilizadores:";
		cin >> filename;
		f.open(filename.c_str());

	}while(f.fail());*/

	f.open("users.txt");

	while(!f.eof())
	{
		string id, n, adress, dest, dh, dm, ah, am, car;
		getline(f, id, ';');
		getline(f, n, ';');
		getline(f, adress, ';');
		getline(f, dest, ';');
		getline(f, dh, ';');
		getline(f, dm, ';');
		getline(f, ah, ';');
		getline(f, am, ';');
		getline(f, car, '\n');
		int uid = atoi(id.c_str());
		int deph = atoi(dh.c_str());
		int depm = atoi(dm.c_str());
		int arrh = atoi(ah.c_str());
		int arrm = atoi(am.c_str());
		int hc = atoi(car.c_str());
		bool hasCar = hc;
		if(uid == 0)
			break;
		User *u = new User(uid, n, adress, dest, deph, depm, arrh, arrm, hasCar);
		g1.addUser(u);
	}
}

/**
 * Reads the informaton of the Vehicles from the file and saves in the vector of Vehicles.
 *
 * @param g1 the Graph
 */
void readVehicles(Graph &g1)
{
	ifstream f;
	string filename;

	/*do
	{
		cout << "Insira o ficheiro com as informacoes dos Veiculos:";
		cin >> filename;
		f.open(filename.c_str());

	}while(f.fail());*/

	f.open("vehicles.txt");

	while(!f.eof())
	{
		string id, n_pass, desv, told, tola;

		getline(f, id, ';');
		getline(f, n_pass, ';');
		getline(f, desv, ';');
		getline(f, told, ';');
		getline(f, tola, '\n');
		int uid = atoi(id.c_str());
		int n_p = atoi(n_pass.c_str());
		double desv_m = atof(desv.c_str());
		int td = atoi(told.c_str());
		int ta = atoi(tola.c_str());
		if(uid == 0)
			break;
		Vehicle *v1 = new Vehicle(uid,n_p,desv_m,td,ta);
		g1.addVehicle(v1);
	}
}

/**
 * Converts a Vertex ID to a lower ID.
 *
 * @param v the vector of vertexs ID
 * @param a the ID of a Vertex
 *
 * @return the new ID or if the ID is not found in the vector -1
 */
int findLonLong(vector<long long> v, long long a)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(v[i] == a){
			return i;
		}
	}
	return -1;
}

/**
 * Searches a Vertex in a specific path.
 *
 * @param g the Graph
 * @param path the Vertex
 * @param v the vector of Vertexs
 * @return true, if the Vertex is found in the vector, otherwise false
 */
bool findVertex1(Graph &g,vector <Vertex *> path,Vertex* v)
{
	for(unsigned int i=0;i<path.size();i++)
	{
		if(path.at(i)->getNode()==v->getNode())
			return true;
	}
	return false;
}

/**
 * Draws all the Vertexs and Edges and paints with different colors the different paths.
 *
 * @param gv the GraphViewer
 * @param g the Graph
 * @param todasAsRotas the vector of Vertexs with all paths
 */
void drawGraph(GraphViewer * gv, Graph &g,vector <vector<Vertex*> >&todasAsRotas)
{
	gv->createWindow(600,600);
	gv->defineEdgeDashed(false);
	gv->defineVertexColor("yellow");
	gv->defineEdgeColor("black");

	double longitude_max=-1000000;
	double latitude_max=-100000;
	double longitude_min=1000000;
	double latitude_min=1000000;

	vector < Vertex*> a = g.getVertexs();
	for(unsigned int x=0;x<g.getVertexs().size();x++)
	{
		if(a.at(x)->getLonG()>longitude_max)
			longitude_max=a.at(x)->getLonG();
		if(a.at(x)->getLatG()>latitude_max)
			latitude_max=a.at(x)->getLatG();
		if(a.at(x)->getLonG()<longitude_min)
			longitude_min=a.at(x)->getLonG();
		if(a.at(x)->getLatG()<latitude_min)
			latitude_min=a.at(x)->getLatG();
	}

	vector<long long> vecTr;

	for(unsigned int i=0;i<a.size();i++)
	{

		vecTr.push_back(a.at(i)->getNode());
		gv->addNode(i,
				6371*(a.at(i)->getLonG()-longitude_min)/(longitude_max-longitude_min)*2 ,
				(600- (6371*(a.at(i)->getLatG()-latitude_min)/(latitude_max-latitude_min)))*2);
	}
	vector<vector <long long> > colorIds= groupCalc(g,todasAsRotas);
	for(unsigned int p=0;p<colorIds.size();p++)
	{
		for(unsigned int r=0;r<colorIds.at(p).size();r++)
		{
			int col = findLonLong(vecTr,colorIds.at(p).at(r));
			if(p==0)
				gv->setVertexColor(col,BLACK);
			else if(p==1)
				gv->setVertexColor(col,PINK);
			else if(p==2)
				gv->setVertexColor(col,BLUE);
			else if(p==3)
				gv->setVertexColor(col,GREEN);
			else if(p==4)
				gv->setVertexColor(col,CYAN);
			else if(p==5)
				gv->setVertexColor(col,RED);
			else if(p==6)
				gv->setVertexColor(col,ORANGE);
			else if(p==7)
				gv->setVertexColor(col,MAGENTA);
			else if(p==8)
				gv->setVertexColor(col,BLACK);

		}
	}
	Edge* col;

	for(unsigned int aa=0;aa<todasAsRotas.size();aa++)
		for(unsigned int bb=0;bb<todasAsRotas.at(aa).size();bb++)
		{
			vector <Edge*> tmp=todasAsRotas.at(aa).at(bb)->getEdgesAdj();
			for(unsigned int cc=0;cc<tmp.size();cc++)
			{
				col = tmp.at(cc);
				if(findVertex1(g,todasAsRotas.at(aa),col->getDest()))
				{
					if(aa==0)
						gv->setEdgeColor(col->getId(),BLACK);
					else if(aa==1)
						gv->setEdgeColor(col->getId(),PINK);
					else if(aa==2)
						gv->setEdgeColor(col->getId(),BLUE);
					else if(aa==3)
						gv->setEdgeColor(col->getId(),GREEN);
					else if(aa==4)
						gv->setEdgeColor(col->getId(),CYAN);
					else if(aa==5)
						gv->setEdgeColor(col->getId(),RED);
					else if(aa==6)
						gv->setEdgeColor(col->getId(),ORANGE);
					else if(aa==7)
						gv->setEdgeColor(col->getId(),MAGENTA);
					else if(aa==8)
						gv->setEdgeColor(col->getId(),BLACK);
				}
			}
		}

	for(unsigned int k=0;k<a.size();k++)
	{
		vector <Edge*> e=a.at(k)->getEdgesAdj();
		for(unsigned int j=0;j<a.at(k)->getEdgesAdj().size();j++)
		{

			int ls = findLonLong(vecTr,a.at(k)->getNode());
			int lp = findLonLong(vecTr,e.at(j)->getDest()->getNode());
			if(a.at(k)->getEdgesAdj().at(j)->getRoad()->getTw())
			{
				gv->addEdge(e.at(j)->getId(),
						ls,
						lp,
						EdgeType::UNDIRECTED);

			}
			else
			{
				gv->addEdge(e.at(j)->getId(),
						ls,
						lp,
						EdgeType::DIRECTED);
			}
		}
	}


	gv->rearrange();
	system("PAUSE");
}

/**
 * Groups all the Users in the same vehicle(considering all the tolerances and maximum deviation)and calculates an unique path.
 *
 * @param g the Graph
 * @param todasAsRotas the vector of Vertexs with all the paths
 */
vector<vector<long long> >groupCalc(Graph &g,vector<vector<Vertex*> > &todasAsRotas)
{
	vector <vector <long long> > todasAsRotasIDs;
	for (unsigned int i=0; i < g.getVehicles().size();i++)
	{
		Vertex * oriDriver = g.getVertexR(g.getRoad(g.getAdressOri(g.getUser(g.getVehicles().at(i)->getDriver()))));
		Vertex * destDriver = g.getVertexR(g.getRoad(g.getAdressDest(g.getUser(g.getVehicles().at(i)->getDriver()))));
		vector <long long> l =g.bfs(oriDriver);

		if (g.searchUser(l,destDriver))
		{
			vector <Vertex *> percurso;
			vector <Vertex *> percursodest;
			percurso.push_back(oriDriver);
			if(g.getVehicles().at(i)->getSeats() > 0)
			{
				for (unsigned int j=0; j < g.saveWithoutVehicle().size(); j++)
				{
					int dHourDriv = g.getDep(g.getUser(g.getVehicles().at(i)->getDriver()));
					int dHourPass = g.getDep(g.saveWithoutVehicle().at(j));
					int deltaD = deltaTime (dHourDriv,dHourPass);

					int aHourDriv = g.getArr(g.getUser(g.getVehicles().at(i)->getDriver()));
					int aHourPass = g.getArr(g.saveWithoutVehicle().at(j));
					int deltaA = deltaTime (aHourPass,aHourDriv);

					Vertex * oriPass = g.getVertexR(g.getRoad(g.getAdressOri(g.saveWithoutVehicle().at(j))));
					Vertex * destPass = g.getVertexR(g.getRoad(g.getAdressDest(g.saveWithoutVehicle().at(j))));

					g.dijkstraShortestPath(oriDriver->getNode());
					if (g.searchUser(l,oriPass))
					{
						if((deltaD >= 0 && deltaD <= g.getVehicles().at(i)->getTolD())
								&& (deltaA >= 0 && deltaA <= g.getVehicles().at(i)->getTolA())
								&& (oriPass->getDist() < g.getVehicles().at(i)->getMaxDev()))
						{
							g.getVehicles().at(i)->addPass(g.saveWithoutVehicle().at(j));
							g.getVehicles().at(i)->setSeats();
							percurso.push_back(oriPass);
							percursodest.push_back(destPass);
						}
					}

				}
			}
			percursodest.push_back(destDriver);
			for(unsigned int m = 0; m < percursodest.size(); m++)
			{
				percurso.push_back(percursodest.at(m));
			}
			bool tudoConectado = true;
			for(unsigned int l = 0; l < percurso.size() - 1; l++)
			{
				g.dijkstraShortestPath(percurso.at(l)->getNode());
				vector <long long> a = g.bfs(percurso.at(l));
				if(!g.searchUser(a, percurso.at(l+1)))
				{
					tudoConectado = false;
				}
			}
			if(tudoConectado)
			{
				vector <Vertex*> rota = g.calcPath(percurso);
				todasAsRotas.push_back(rota);

			}
		}

	}
	for(unsigned int qq = 0; qq < todasAsRotas.size(); qq++)
	{
		vector< long long> rotaIds;
		for(unsigned int ww = 0; ww < todasAsRotas.at(qq).size(); ww++)
		{
			rotaIds.push_back(todasAsRotas.at(qq).at(ww)->getNode());
		}
		todasAsRotasIDs.push_back(rotaIds);
	}


	return todasAsRotasIDs;
}

void showRoutes(vector<vector<Vertex*> > &v)
{
	string a = "asdfg";
	ofstream output;
	output.open("routes.txt");
	vector<vector<Road*> > routesByRoads;
	for(unsigned int i = 0; i < v.size(); i++)
	{
		vector<Road*> routeByRoads;

		for(unsigned int j = 0; j < v.at(i).size()-1; j++)
		{
			for(unsigned int k = 0; k < v.at(i).at(j)->getEdgesAdj().size(); k++)
			{
				if(v.at(i).at(j+1)->getNode() == v.at(i).at(j)->getEdgesAdj().at(k)->getDest()->getNode())
				{
					if(!v.at(i).at(j)->getEdgesAdj().at(k)->getRoad()->getName().empty()) // elimina as que são nulas
					{
						if ((a.compare(v.at(i).at(j)->getEdgesAdj().at(k)->getRoad()->getName()))!=0)//elimina ruas iguais
						{
							routeByRoads.push_back(v.at(i).at(j)->getEdgesAdj().at(k)->getRoad());
							a = v.at(i).at(j)->getEdgesAdj().at(k)->getRoad()->getName();
						}
					}
				}

			}
		}
		routesByRoads.push_back(routeByRoads);
	}
	for(unsigned int l = 0; l < routesByRoads.size(); l++)
	{
		cout << "Rota " << l << ":" << endl;
		for(unsigned int o = 0; o < routesByRoads.at(l).size();o++)
		{
			cout << routesByRoads.at(l).at(o)->getName()<< endl;
			output << l << ";" << routesByRoads.at(l).at(o)->getName()<< endl;
		}
	}
	output.close();
}

void writePassengers(vector<Vehicle*> v)
{
	ofstream output;
	output.open("passengers.txt");
	for(unsigned int i = 0; i < v.size(); i++)
	{
		for(unsigned int j = 0; j < v.at(i)->getPassengers().size(); j++)
		{
			output << i << ";" << v.at(i)->getPassengers().at(j)->getName() << endl;
		}
	}
	output.close();
}

