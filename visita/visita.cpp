#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
	vector<int> neigh;
	bool visited;
};

int main(){
	int n,m,r;
	vector<node> graph;

	ifstream in("input.txt");
	in>>n>>m>>r;

	graph.resize(n);

	for(int i=0; i<m;i++){
		int from,to;
		in>>from>>to;
		graph[from].neigh.push_back(to);
	}

	queue <int> s;
	s.push(r);
	graph[r].visited=true;

	int count =1;

	while(!s.empty())
	{
		r=s.front();
		s.pop();

		for(int i:graph[r].neigh){
			if(!graph[i].visited){
				graph[i].visited=true;
				s.push(i);
				count++;
			}
		}
	}
	ofstream out("output.txt");
	out <<count<<endl;
}
/*

Visita di un grafo orientato (visita)
Difficolta D = 1 (tempo limite 1 sec). `
Descrizione del problema
Dato un grafo orientato e un nodo di partenza S, calcolate il numero di nodi raggiungibile da S.
Dati di input
La prima riga contiene tre interi, N, M e S. N e il numero di nodi, M il numero di archi, S il nodo di ´
partenza. Le successive M righe contengono due interi per riga, il nodo di partenza e di arrivo degli
archi.
Dati di output
Un intero, uguale al numero di nodi raggiungibili da S (S incluso)
Assunzioni
• 1 ≤ N ≤ 10000
• 1 ≤ M ≤ 100000
Esempi di input/output
File input.txt File output.txt
5 6 1
0 2
0 4
1 4
3 2
2 4
4 3
4
Nota/e
• Dal nodo 1 si possono raggiungere i nodi 2,3 e 4. In totale si possono raggiungere 4 nodi.

*/