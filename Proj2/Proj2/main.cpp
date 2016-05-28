#include "Interface.h"

Graph g;
vector<Road*> estradas;
GraphViewer *gv = new GraphViewer(600, 600,false);
vector<vector<Vertex*> > todasAsRotas;
vector<vector<Road*> > routesByRoads;
vector<int> idRotas;
vector<int> idVehicle;


void pesqExataRuas()
{
	string rua;
	int numRuas;
	cout << "Estão disponíveis " << g.getVehicles().size() << " veículos." << endl;
	cout << "Introduza a rua a pesquisar:" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, rua);
	numRuas = numStringMatchingRuas("routes.txt",rua, idRotas);
	if(numRuas == 0)
	{
		cout << "Não há rotas disponíveis para essa rua";
	}
	else
	{
		cout << "Há " << idRotas.size() <<" rotas com essa rua:" << endl;
		showRoutes(idRotas,routesByRoads);
	}
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
	numVehicles = numStringMatchingUsers("passenger.txt",user, idVehicle);
	if(numVehicles == 0)
	{
		cout << "Não há veículos com esse passageiro";
	}
	else
	{
		cout << "Há " << idVehicle.size() <<" com esse passageiro:" << endl;
		//showRoutes(idRotas,routesByRoads); FALTA FAZER SHOWUSERS
	}
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
		cin >> num;
	}

	if(num == 3)
		return 0;
	return num;
}

void searchMenuRuas()
{
	int opcao;
	while((opcao = MenuRuas()))
	{
		switch(opcao)
		{
		case 1:
			pesqExata();
			break;
		case 2:
			cout<< "boas";
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
		cin >> num;
	}

	if(num == 3)
		return 0;
	return num;
}

void searchMenuUsers()
{
	int opcao;
	while((opcao = MenuUsers()))
	{
		switch(opcao)
		{
		case 1:
			pesqExataRuas();
			break;
		case 2:
			cout<< "boas";
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
			cout << "utilizador" << endl;
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




















