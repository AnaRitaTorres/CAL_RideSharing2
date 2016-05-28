#include "Interface.h"

	Graph g;
	vector<Road*> estradas;
	GraphViewer *gv = new GraphViewer(600, 600,false);
	vector<vector<Vertex*> > todasAsRotas;


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

		return num;
	}

	void optionMenu()
	{
		int num = initialMenu();
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
		switch(num)
		{
		case 1:
			drawGraph(gv,g,todasAsRotas);
			optionMenu();
			break;
		case 2:
			cout << "rua" << endl ;
			optionMenu();
			break;
		case 3:
			cout << "utilizador" << endl;
			optionMenu();
			break;
		case 4:
			break;

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
	showRoutes(todasAsRotas);
	writePassengers(g.getVehicles());
	optionMenu();
}




















