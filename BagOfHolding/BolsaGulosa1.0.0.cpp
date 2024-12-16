// Tema: Bolsa devoradora
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

// Structs
struct Ponto
{
	float x, y;
};

struct Edge
{
	int dest, sim;
};

struct Item
{
	string nome;
	string dono;
	string magia;
	int raridade;
	int id;
	list<Edge> vizinhos;
};

struct Treenode
{
	Item info;
	Treenode *esq;
	Treenode *dir;
};

typedef Treenode *Treenodeptr;


// Fun��es
// Inser��o em �rvores
void tInsereID(Treenodeptr &p, Item novo)
{
	if (p == NULL)
	{
		p = new Treenode;
		p->info = novo;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (novo.id < p->info.id)
	{
		tInsereID(p->esq, novo);
	}
	else if (novo.id > p->info.id)
	{
		tInsereID(p->dir, novo);
	}
	else
	{
		cout << "\nID j� cadastrado" << endl;
	}
}

void tInsereName(Treenodeptr &p, Item novo)
{
	if (p == NULL)
	{
		p = new Treenode;
		p->info = novo;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (novo.nome < p->info.nome)
	{
		tInsereName(p->esq, novo);
	}
	else if (novo.nome > p->info.nome)
	{
		tInsereName(p->dir, novo);
	}
	else
	{
		cout << "\nNome j� cadastrado" << endl;
	}
}

void tInsereRar(Treenodeptr &p, Item novo)
{
	if (p == NULL)
	{
		p = new Treenode;
		p->info = novo;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (novo.raridade < p->info.raridade)
	{
		tInsereRar(p->esq, novo);
	}
	else
	{
		tInsereRar(p->dir, novo);
	}
}

// Pesquisa em �rvores
Treenodeptr tPesqID(Treenodeptr p, int id)
{
	if (p == NULL) return NULL;
	else if (id == p->info.id) return p;
	else if (id < p->info.id) return tPesqID(p->esq, id);
	else return tPesqID(p->dir, id);
}

Treenodeptr tPesqName(Treenodeptr p, string name)
{
	if (p == NULL) return NULL;
	else if (name == p->info.nome) return p;
	else if (name < p->info.nome) return tPesqName(p->esq, name);
	else return tPesqName(p->dir, name);
}

// Algoritmo geometrico
bool analise_poligonal()
{
	list<Ponto> poligono;
	Ponto pontotemp;
	
	cout << "\nDigite em ordem os pontos do pol�gono" << endl;
	cout << "Digite um valor menor que 0 para concluir" << endl;
	
	while (cin >> pontotemp.x >> pontotemp.y && pontotemp.x >= 0 && pontotemp.y >= 0)
	{
		poligono.push_back(pontotemp);
	}
	
	list<Ponto>::iterator p;
	list<Ponto>::iterator pp;
	
	for (p = poligono.begin(); p != --poligono.end(); p++)
	{
		for (pp = p; pp != poligono.end(); pp++)
		{
			if (pp != p)
			{
				float distancia = sqrt(pow((p->x - pp->x),2) + pow((p->y - pp->y),2));
				if (distancia >= 40)
				{
					cout << "\nA dist�ncia entre: (" << p->x << "," << p->y << ") e (" << pp->x << "," << pp->y << ") � de: " << distancia << " cm" << endl;
					cout << "O item � grande demais para a bolsa" << endl;
					cout << "\nPor favor inicie um novo cadastro" << endl;
					return false;
				}
			}
		}
	}
	
	cout << "Nenhuma dist�ncia � maior que o di�metro da bolsa!" << endl;
	cout << "Item cadastrado com sucesso!" << endl;
	return true;
}

// Fun��es auxiliares
bool verificar_escola(string magia)
{
	if (magia == "Abjuracao") return true;
	if (magia == "Conjuracao") return true;
	if (magia == "Adivinhacao") return true;
	if (magia == "Encantamento") return true;
	if (magia == "Evocacao") return true;
	if (magia == "Ilusao") return true;
	if (magia == "Necromancia") return true;
	if (magia == "Transmutacao") return true;

	cout << "Escola inv�lida" << endl;
	return false;
}

void errormacro()
{
	while (true)
	{
		cout << "ERRO";
	}
}

Item cadastrar()
{
	Item novo;
	bool flag = false;
	
	while (!flag)
	{
		cout << "\nNome: ";
		getline(cin >> ws, novo.nome);
		if (novo.nome == "Bolsa devoradora") errormacro(); // frescura
		cout << "\nDono: ";
		getline(cin >> ws, novo.dono);
		cout << "\nEscola: ";
		cout << "\n- Abjuracao\n- Conjuracao\n- Adivinhacao\n- Encantamento\n- Evocacao\n- Ilusao\n- Necromancia\n- Transmutacao" << endl;
		do
		{
			cin >> novo.magia;
		}
		while (!verificar_escola(novo.magia));
		cout << "\nID: ";
		cin >> novo.id;
		cout << "\nRaridade 0|100: ";
		do
		{
			cin >> novo.raridade;
		}
		while (novo.raridade < 0 || novo.raridade > 100);

		flag = analise_poligonal();
	}

	return novo;
}

void mostrar(Treenodeptr arvoreid, int id)
{
	Treenodeptr show = tPesqID(arvoreid, id);
	if (show != NULL)
	{
		cout << "\n\nNome: " << show->info.nome << endl;
		cout << "\nDono: " << show->info.dono << endl;
		cout << "\nEscola: " << show->info.magia << endl;
		cout << "\nID: " << show->info.id << endl;
		cout << "\nRaridade: " << show->info.raridade << endl << endl;
	}
	else
	{
		cout << "\nItem n�o encontrado" << endl;
	}
}

// Percurso em �rvores
void emOrdem(Treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		mostrar(arvore, arvore->info.id);
		emOrdem(arvore->dir);
	}
}

void medrOme(Treenodeptr arvore)
{
	if (arvore != NULL)
	{
		medrOme(arvore->dir);
		mostrar(arvore, arvore->info.id);
		medrOme(arvore->esq);
	}
}

void contaescola(Treenodeptr t)
{
	// Abjuracao Conjuracao Adivinhacao Encantamento Evocacao Ilusao Necromancia Transmutacao
	int contador[8];
	for (int i = 0; i < 8; i++) contador[i] = 0;

	Treenodeptr n;
	list<Treenodeptr> q;

	if (t != NULL)
	{
		q.push_back(t);
		while (!q.empty())
		{
			n = q.front();
			q.pop_front();

			if (n->esq != NULL)
				q.push_back(n->esq);
			if (n->dir != NULL)
				q.push_back(n->dir);

			// contagem das escolas
			if (n->info.magia == "Abjuracao") contador[0]++;
			if (n->info.magia == "Conjuracao") contador[1]++;
			if (n->info.magia == "Adivinhacao") contador[2]++;
			if (n->info.magia == "Encantamento") contador[3]++;
			if (n->info.magia == "Evocacao") contador[4]++;
			if (n->info.magia == "Ilusao") contador[5]++;
			if (n->info.magia == "Necromancia") contador[6]++;
			if (n->info.magia == "Transmutacao") contador[7]++;
		}
	}

	cout << "-Abjura��o: " << contador[0] << endl;
	cout << "-Conjura��o: " << contador[1] << endl;
	cout << "-Adivinha��o: " << contador[2] << endl;
	cout << "-Encantamento: " << contador[3] << endl;
	cout << "-Evoca��o: " << contador[4] << endl;
	cout << "-Ilus�o: " << contador[5] << endl;
	cout << "-Necromancia: " << contador[6] << endl;
	cout << "-Transmuta��o: " << contador[7] << endl;
}

// Remo��o em �rvores
Treenodeptr tMenor(Treenodeptr &raiz)
{
	Treenodeptr t;

	t = raiz;
	if (t->esq == NULL)
	{
		raiz = raiz->dir;
		return t;
	}
	else return tMenor(raiz->esq);
}

void tRemoveId(Treenodeptr &raiz, int x)
{
	Treenodeptr p;
	if (raiz == NULL) return;
	if (x == raiz->info.id)
	{
		p = raiz;
		if (raiz->esq == NULL) raiz = raiz->dir;
		else if (raiz->dir == NULL) raiz = raiz->esq;
		else
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;
		return;
	}
	else
	{
		if (x < raiz->info.id)
		{
			return tRemoveId (raiz->esq, x);
		}
		else
		{
			return tRemoveId (raiz->dir, x);
		}
	}
}

void tRemoveName(Treenodeptr &raiz, string x)
{
	Treenodeptr p;
	if (raiz == NULL) return;
	if (x == raiz->info.nome)
	{
		p = raiz;
		if (raiz->esq == NULL) raiz = raiz->dir;
		else if (raiz->dir == NULL) raiz = raiz->esq;
		else
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;
		return;
	}
	else
	{
		if (x < raiz->info.nome)
		{
			return tRemoveName (raiz->esq, x);
		}
		else
		{
			return tRemoveName (raiz->dir, x);
		}
	}
}

void tRemoveRar(Treenodeptr &raiz, int x)
{
	Treenodeptr p;

	if (raiz == NULL) return;

	if (x == raiz->info.raridade)
	{
		p = raiz;
		if (raiz->esq == NULL)
		{
			raiz = raiz->dir;
		}
		else
		{
			if (raiz->dir == NULL)
			{
				raiz = raiz->esq;
			}
			else
			{
				p = tMenor(raiz->dir);
				raiz->info = p->info;
			}
			delete p;
			return;
		}
	}
	else
	{
		if (x < raiz->info.raridade)
		{
			return tRemoveRar(raiz->esq, x);
		}
		else
		{
			return tRemoveRar(raiz->dir, x);
		}
	}
}

void limpaRar(Treenodeptr arvore, Treenodeptr &arvorerar, Treenodeptr &arvoreid, Treenodeptr &arvorename, int limrar)
{
	if (arvore != NULL)
	{
		limpaRar(arvore->esq, arvorerar, arvoreid, arvorename, limrar);
		if (arvore->info.raridade < limrar)
		{
			tRemoveRar(arvorerar, arvore->info.raridade);
			tRemoveId(arvoreid, arvore->info.id);
			tRemoveName(arvorename, arvore->info.nome);
		}
		limpaRar(arvore->dir, arvorerar, arvoreid, arvorename, limrar);
	}
}

void tDesmatar(Treenodeptr &arvore)
{
	if (arvore == NULL)
	{
		tDesmatar(arvore->esq);
		tDesmatar(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}


// Fun��es de grafos
void criagrafo(Treenodeptr arvoreid)
{
	int orig, dest, sim;
	Treenodeptr origemptr, destinoptr;

	cout << "Digite os ids e o valor de similaridade" << endl;
	cout << "Digite um valor inv�lido para sair" << endl;
	while (cin >> orig >> dest >> sim && orig >= 0 && dest >= 0 && sim > 0)
	{
		origemptr = tPesqID(arvoreid, orig);
		destinoptr = tPesqID(arvoreid, dest);

		if (origemptr != NULL && destinoptr != NULL)
		{
			(origemptr->info.vizinhos).push_back( {dest, sim});
			(destinoptr->info.vizinhos).push_back( {orig, sim});
		}
		else
		{
			cout << "Iten(s) n�o encontrado(s)" << endl;
		}
	}
}

void listargrafo(Treenodeptr arvoreid)
{
	int id, simmin;
	string player;
	Treenodeptr origem, destino;
	string nametemp;

	list<Edge>::iterator p;
	cout << "Digite respectivamente o nome do jogador, a similaridade minima e o id do item" << endl;
	getline(cin >> ws, player);
	cin >> simmin >> id;

	origem = tPesqID(arvoreid, id);
	if (origem != NULL)
	{
		for (p = (origem->info.vizinhos).begin(); p != (origem->info.vizinhos).end(); p++)
		{
			destino = tPesqID(arvoreid, p->dest);
			if (destino != NULL)
			{
				nametemp = destino->info.dono;
				if (nametemp != player && p->sim >= simmin)
				{
					mostrar(arvoreid, p->dest);
				}
			}
		}
	}
}

// Driver principal
int main()
{
	setlocale(LC_ALL, "Portuguese");

	// Arvores
	Treenodeptr arvoreid = NULL;
	Treenodeptr arvorename = NULL;
	Treenodeptr arvorerar = NULL;

	// Variaveis auxiliares:
	bool exit = false;
	string stringtemp;
	Item itemtemp;
	int inttemp;

	// Inicializa��o:
	cout << "RRRRARWWWWAR!!!! EU SOU A BOLSA DEVORADORA, ME DE ITENS AGORA!!!" << endl;
	itemtemp = cadastrar();
	tInsereID(arvoreid, itemtemp);
	tInsereName(arvorename, itemtemp);
	tInsereRar(arvorerar, itemtemp);

	// Loop principal:
	int opt;

	while (!exit)
	{
		cout << "\nSelecione uma op��o v�lida" << endl;
		cout << "0- Cadastrar novo item" << endl;
		cout << "1- Mostrar dados de um item" << endl;
		cout << "2- Definir Similaridade" << endl;
		cout << "3- Listar itens por similaridade" << endl;
		cout << "4- Listar por ordem alfab�tica" << endl;
		cout << "5- Verificar por nome" << endl;
		cout << "6- Listar por raridade" << endl;
		cout << "7- Contar escola" << endl;
		cout << "8- Remo��o por raridade" << endl;
		cout << "9- Sair" << endl;

		cin >> opt;

		switch (opt)
		{
			
		case 0:
			itemtemp = cadastrar();
			tInsereID(arvoreid, itemtemp);
			tInsereName(arvorename, itemtemp);
			tInsereRar(arvorerar, itemtemp);
			break;

		case 1:
			cin >> inttemp;
			mostrar(arvoreid, inttemp);
			break;
		
		case 2:
			criagrafo(arvoreid);
			break;
		
		case 3:
			listargrafo(arvoreid);
			break;
		
		case 4:
			emOrdem(arvorename);
			break;
		
		case 5:
			getline(cin >> ws, stringtemp);
			if (tPesqName(arvorename, stringtemp) != NULL)
			{
				cout << "Item encontrado" << endl;
			}
			else cout << "Item n�o encontrado" << endl;
			break;
		
		case 6:
			medrOme(arvorerar);
			break;
		
		case 7:
			contaescola(arvoreid);
			break;
		
		case 8:
			cout << "Digite o limite de raridade: ";
			do
			{
				cin >> inttemp;
			}
			while (inttemp < 0 || inttemp > 100);
			limpaRar(arvorerar, arvorerar, arvoreid, arvorename, inttemp);
			break;
		
		default:
			exit = true;
			break;
		}
	}

	// Desmatamento
	tDesmatar(arvoreid);
	tDesmatar(arvorename);
	tDesmatar(arvorerar);
	return 0;
}