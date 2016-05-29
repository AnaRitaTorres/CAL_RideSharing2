#include "Interface.h"

Graph g;
vector<Road*> estradas;
GraphViewer *gv = new GraphViewer(600, 600,false);
vector<vector<Vertex*> > todasAsRotas;
vector<vector<Road*> > routesByRoads;
vector<int> idRotas;
vector<int> idVehicle;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter() {
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";
    PCFreq = double(li.QuadPart)/1000.0;
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}


void pesqExataRuas()
{
	string rua;
	int numRuas;
	cout << "Estão disponíveis " << g.getVehicles().size() << " veículos." << endl;
	cout << "Introduza a rua a pesquisar:" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, rua);
    StartCounter();
	numRuas = numStringMatchingRuas("routes.txt",rua, idRotas);
	double t = GetCounter();
	if(numRuas == 0)
	{
		cout << "Não há rotas disponíveis para essa rua" << endl;
	}
	else
	{
		cout << "Há " << idRotas.size() <<" rotas com essa rua:" << endl;
		showRoutes(idRotas,routesByRoads);
	}
	cout << "decorreram " << t << endl;
}

void pesqExataUsers()
{
	string user;
	int numVehicles;
	cout << "Estão disponíveis " << g.getVehicles().size() << " veículos." << endl;
	cout << "Introduza o nome do passageiro a pesquisar:" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, user);
	StartCounter();
	numVehicles = numStringMatchingUsers("passengers.txt",user, idVehicle);
	double t = GetCounter();
	vector< Vehicle*> v = g.getVehicles();
	if(numVehicles == 0)
	{
		cout << "Não há veículos com esse passageiro" << endl;
	}
	else
	{
		cout << "Há " << idVehicle.size() <<" com esse passageiro:" << endl;
		showVehicle(idVehicle,v);
	}
	cout << "decorreram " << t << endl;
}

void pesqAproxRuas()
{
	string rua;
	float numRuas;
	cout << "Introduza a rua a pesquisar:" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, rua);
	StartCounter();
	numRuas = numApproximateStringMatching("routes.txt",rua);
	double t = GetCounter();
	cout << "O resultado da pesquisa aproximada é "<< numRuas << endl;
	cout << "decorreram " << t << endl;
}

void pesqAproxUsers()
{
	string nome;
	float numVehicles;
	cout << "Introduza o passageiro a pesquisar:" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, nome);
	numVehicles = numApproximateStringMatching("passengers.txt",nome);
	double t = GetCounter();
	cout << "O resultado da pesquisa aproximada é "<< numVehicles << endl;
	cout << "decorreram " << t << endl;
}

unsigned short int initialMenu()
{
	int num;

	cout << TAB << "1 - Visualizar Grafo" << endl;
	cout << TAB << "2 - Pesquisar por Rua" << endl;
	cout << TAB << "3 - Pesquisar por Utilizador" << endl;
	cout << TAB << "4 - Sair" << endl;

	cin >> num;

	while (num < 1 || num > 4)
	{
		cout << "Opção inválida!" << endl;
		cin.clear();
		cin.ignore();
		cin >> num;
	}

	if(num==4)
		return 0;

	return num;
}

int MenuRuas()
{
	int num;
	cout << TAB << "1 - Pesquisa exata" << endl;
	cout << TAB << "2 - Pesquisa aproximada" << endl;
	cout << TAB << "3 - Voltar" << endl;

	cin >> num;

	while (num < 1 || num > 3)
	{
		cout << "Opção inválida!" << endl;
		cin.clear();
		cin.ignore();
		cin >> num;
	}

	if(num == 3)
		return 0;
	return num;
}

void searchMenuRuas()
{
	int opcao;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	while((opcao = MenuRuas()))
	{
		switch(opcao)
		{
		case 1:
			pesqExataRuas();
			break;
		case 2:
			pesqAproxRuas();
			break;

		}
	}
}

int MenuUsers()
{
	int num;
	cout << TAB << "1 - Pesquisa exata" << endl;
	cout << TAB << "2 - Pesquisa aproximada" << endl;
	cout << TAB << "3 - Voltar" << endl;

	cin >> num;

	while (num < 1 || num > 3)
	{
		cout << "Opção inválida!" << endl;
		cin.clear();
		cin.ignore();
		cin >> num;
	}

	if(num == 3)
		return 0;
	return num;
}

void searchMenuUsers()
{
	int opcao;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	while((opcao = MenuUsers()))
	{
		switch(opcao)
		{
		case 1:
			pesqExataUsers();
			break;
		case 2:
			pesqAproxUsers();
			break;

		}
	}
}

void optionMenu()
{
	int opcao;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	while((opcao = initialMenu()))
	{
		switch(opcao)
		{
		case 1:
			drawGraph(gv,g,todasAsRotas);
			break;
		case 2:
			searchMenuRuas();
			break;
		case 3:
			searchMenuUsers();
			break;
		case 4:
			break;
		}
	}
}


int main()
{
	readCoords(g);
	readRoadName(estradas);
	readRoadConnect(g,estradas);
	readUsers(g);
	readVehicles(g);
	g.setEdgesID();
	groupCalc(g,todasAsRotas);
	writeRoutes(todasAsRotas, routesByRoads);
	writePassengers(g.getVehicles());
	optionMenu();
}




















