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
	f.close();
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
	f.close();
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

		vector<Road *>  e = estradas;
		for (unsigned int j=0; j < e.size(); j++)
		{
			if (e.at(j)->getRoadId()== road)
			{
				saveRoad= e.at(j);
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
	f.close();
	vector<Road *> a = estradas;
	for(unsigned int k=0; k < a.size(); k++)
	{
		g1.addRoad(a.at(k));
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
	f.close();
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
	f.close();
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
 *
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
	for(unsigned int x=0;x<a.size();x++)
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
 *
 * @return vector of ids of the routes
 */
vector<vector<long long> >groupCalc(Graph &g,vector<vector<Vertex*> > &todasAsRotas)
												{
	vector <vector <long long> > todasAsRotasIDs;
	vector < Vehicle *> ve = g.getVehicles();
	for (unsigned int i=0; i < ve.size();i++)
	{
		Vertex * oriDriver = g.getVertexR(g.getRoad(g.getAdressOri(g.getUser(ve.at(i)->getDriver()))));
		Vertex * destDriver = g.getVertexR(g.getRoad(g.getAdressDest(g.getUser(ve.at(i)->getDriver()))));
		vector <long long> l =g.bfs(oriDriver);

		if (g.searchUser(l,destDriver))
		{
			vector <Vertex *> percurso;
			vector <Vertex *> percursodest;
			percurso.push_back(oriDriver);
			vector<User *> s = g.saveWithoutVehicle();

			if(ve.at(i)->getSeats() > 0)
			{
				for (unsigned int j=0; j < s.size(); j++)
				{
					int dHourDriv = g.getDep(g.getUser(ve.at(i)->getDriver()));
					int dHourPass = g.getDep(s.at(j));
					int deltaD = deltaTime (dHourDriv,dHourPass);

					int aHourDriv = g.getArr(g.getUser(ve.at(i)->getDriver()));
					int aHourPass = g.getArr(s.at(j));
					int deltaA = deltaTime (aHourPass,aHourDriv);

					Vertex * oriPass = g.getVertexR(g.getRoad(g.getAdressOri(s.at(j))));
					Vertex * destPass = g.getVertexR(g.getRoad(g.getAdressDest(s.at(j))));

					g.dijkstraShortestPath(oriDriver->getNode());
					if (g.searchUser(l,oriPass))
					{
						if((deltaD >= 0 && deltaD <= ve.at(i)->getTolD())
								&& (deltaA >= 0 && deltaA <= ve.at(i)->getTolA())
								&& (oriPass->getDist() < ve.at(i)->getMaxDev()))
						{
							ve.at(i)->addPass(s.at(j));
							ve.at(i)->setSeats();
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

/**
 * Writes the routes to a txt file.
 *
 * @param v the vector of vectors of Vertexs
 * @param v1 the vector of vectors of Roads
 */
void writeRoutes(vector<vector<Vertex*> > &v, vector<vector<Road*> > &v1)
{
	string a = "asdfg";
	ofstream output;
	output.open("routes.txt");
	for(unsigned int i = 0; i < v.size(); i++)
	{
		vector<Road*> routeByRoads;

		for(unsigned int j = 0; j < v.at(i).size()-1; j++)
		{
			for(unsigned int k = 0; k < v.at(i).at(j)->getEdgesAdj().size(); k++)
			{
				if(v.at(i).at(j+1)->getNode() == v.at(i).at(j)->getEdgesAdj().at(k)->getDest()->getNode())
				{
					if(!v.at(i).at(j)->getEdgesAdj().at(k)->getRoad()->getName().empty()) // elimina as que s�o nulas
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
		v1.push_back(routeByRoads);
	}
	for(unsigned int l = 0; l < v1.size(); l++)
	{
		for(unsigned int o = 0; o < v1.at(l).size();o++)
		{
			output << l << ";" << v1.at(l).at(o)->getName()<< endl;
		}
	}
	output.close();
}

/**
 * Writes the names of the passengers of a specific value.
 *
 * @param vector of vehicles
 *  */
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

/**
 * Preprocessing of the string to examine.
 *
 * @param pattern the string to examine
 * @param prefix the vector of integers
 */
void pre_kmp(string pattern, vector<int> & prefix)
{
	int m=pattern.length();
	prefix[0]=-1;
	int k=-1;
	for (int q=1; q<m; q++) {
		while (k>-1 && pattern[k+1]!=pattern[q])
			k = prefix[k];
		if (pattern[k+1]==pattern[q]) k=k+1;
		prefix[q]=k;
	}
}

/**
 * The Knuth-Morris_Pratt algorithm.
 *
 * @param text the string to examine
 * @param pattern the string to find in the text
 */

int kmp(string text, string pattern)
{
	int num=0;
	int m=pattern.length();
	vector<int> prefix(m);
	pre_kmp(pattern, prefix);

	int n=text.length();

	int q=-1;
	for (int i=0; i<n; i++) {
		while (q>-1 && pattern[q+1]!=text[i])
			q=prefix[q];
		if (pattern[q+1]==text[i])
			q++;
		if (q==m-1) {
			num++;
			q=prefix[q];
		}
	}
	return num;
}

/**
 * Number of occurrences of a street in the routes file and saves in a vector to which route it belongs to.
 *
 * @param filename the name of the file to search in
 * @param toSearch the string to look for in the file
 * @param v the vector where the route ID is saved
 *
 * @return number of occurrences of a street
 */
int numStringMatchingRuas(string filename,string toSearch, vector<int> &v)
{
	ifstream fich(filename.c_str());
	if (!fich)
	{ cout << "Erro a abrir ficheiro de leitura\n"; return 0; }

	string line1;
	string idRota;
	int idR;
	int num=0;

	while (!fich.eof()) {
		getline(fich, idRota, ';');
		idR = atoi(idRota.c_str());
		getline(fich, line1);
		int tmp = kmp(line1,toSearch);
		num+=tmp;
		if(tmp>0)
			v.push_back(idR);

	}
	fich.close();
	return num;
}

/**
 * Number of occurrences of a user in the passengers file and saves in a vector to which car it belongs to.
 *
 * @param filename the name of the file to search in
 * @param toSearch the string to look for in the file
 * @param v the vector where the vehicle ID is saved
 *
 * @return number of occurrences of a passenger
 */
int numStringMatchingUsers(string filename,string toSearch, vector<int> &v)
{
	ifstream fich(filename.c_str());
	if (!fich)
	{ cout << "Erro a abrir ficheiro de leitura\n"; return 0; }

	string line1;
	string idVehicle;
	int idV;
	int num=0;

	while (!fich.eof()) {
		getline(fich, idVehicle, ';');
		idV = atoi(idVehicle.c_str());
		getline(fich, line1);
		int tmp = kmp(line1,toSearch);
		num+=tmp;
		if(tmp>0)
			v.push_back(idV);

	}
	fich.close();
	return num;
}

/**
 * Prints the routes to the console.
 *
 * @param ids the vector where the IDs of the routes are.
 * @param v2 the vector of vectors of roads where the routes are.
 */
void showRoutes(vector <int> ids, vector<vector<Road*> > & v2)
{

	for(unsigned int i = 0; i < ids.size(); i++)
	{
		int x = ids.at(i);
		cout << "Rota " << x <<":" << endl;
		for(unsigned int j = 0; j < v2.at(x).size(); j++)
			cout << v2.at(x).at(j)->getName() << endl;
	}
}

/**
 * Prints the vehicles to the console.
 *
 * @param ids the vector where the IDs of the vehicles are.
 * @param v2 the vector of vectors of vehicles where the passengers are.
 */
void showVehicle(vector <int> ids1, vector<Vehicle*> & v3)
{
	for(unsigned int i = 0; i < ids1.size(); i++)
	{
		int x = ids1.at(i);
		cout << "Veiculo " << x <<":" << endl;
	}
}

/*
 * Minimum number of alterations to make the line where the string is searched in the string itself.
 *
 * @param pattern the string to search
 * @param text the string where the pattern is searched
 */
int editDistance(string pattern, string text)
{
	int n=text.length();
	vector<int> d(n+1);
	int old,neww;
	for (int j=0; j<=n; j++)
		d[j]=j;
	int m=pattern.length();
	for (int i=1; i<=m; i++) {
		old = d[0];
		d[0]=i;
		for (int j=1; j<=n; j++) {
			if (pattern[i-1]==text[j-1]) neww = old;
			else {
				neww = min(old,d[j]);
				neww = min(neww,d[j-1]);
				neww = neww +1;
			}
			old = d[j];
			d[j] = neww;
		}
	}
	return d[n];
}

/*
 * Minimum number of alterations to make the text where the string is searched in the string itself.
 *
 * @param pattern the string to search
 * @param text the string where the pattern is searched
 */
float numApproximateStringMatching(string filename,string toSearch)
{
	ifstream fich(filename.c_str());
	if (!fich)
	{ cout << "Erro a abrir ficheiro de leitura\n"; return 0; }

	string line1, word1;
	int num=0, nwords=0;

	while (!fich.eof()) {
		num=0;
		string idV;
		getline(fich, idV, ';');
		getline(fich,line1);
		stringstream s1(line1);
		num += editDistance(toSearch, line1);
			if(num <= 6)
				cout << line1 << endl;
			nwords++;
}
	fich.close();
	float res=(float)num/nwords;
	return res;
}





