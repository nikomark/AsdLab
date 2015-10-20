/*
Ordinamento pesato (sortpesato)
Difficolta D = 3 (tempo limite 2 sec). `
Descrizione del problema
Vi viene dato un array di N interi da ordinare. Gli elementi sono tutti diversi, anzi sono precisamente
tutti gli interi fra 1 e N. Visto che sarebbe troppo facile ordinare un array del genere, abbiamo delle
restrizioni.
Ad ogni turno potete scambiare due elementi a scelta dell’array. Per fare cio, pagate un prezzo ´
pari alla somma dei due elementi. Per scambiare di posto l’elemento 3 e l’elemento 4 impiegate un
turno e pagate 7.
Voi dovete risolvere due problemi: quale e il metodo pi ´ u veloce (che ottimizza il numero di turni) ´
ed il metodo piu economico (che ottimizza il prezzo). ´
Dati di input
La prima riga contiene N, la lunghezza dell’array. La riga successiva contiene l’array, con gli elementi
separati da spazio.
Dati di output
L’output contiene due interi. Il primo intero rappresenta S, il numero minimo di turni per ottenere
l’array ordinato. Il secondo intero rappresenta P. il prezzo minimo per ordinare l’array.
Assunzioni
• 1 ≤ N ≤ 100000
Valutazione delle soluzioni
• Se il programma computa correttamente S ma non P, prendera un met ´ a dei punti. Se il pro- ´
gramma computa correttamente P ma non S, prendera tre quarti dei punti. ´
Esempi di input/output
File input.txt File output.txt
4
3 2 4 1
2 9

Nota/e
• Nell’esempio, una sequenza di lunghezza minima e scambiare di posizione 1 e 3 e poi scambiare ´
3 e 4. La sequenza di costo minimo e scambiare prima 1 e 4, poi 1 e 3. 

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;
vector <bool> visite;

int main(){

	int n;

	ifstream in("input.txt");
	in>>n;

	arr.resize(n+1);
	visite.resize(n+1, false);

	for(int i=1;i<=n; i++){
		in>>arr[i];
		//cout <<arr[i]<<endl;
	}

	int moves=0;
	int price =0;

	for(int i=1; i<=n; i++){
		if(!visite[i])
		{
			if(arr[i]!=i)
			{
				int sum=0;
				int num=0;
				int mn =10000000;
				int cur=i;

				while(!visite[arr[cur]])
				{
					mn= min (mn, arr[cur]);
					sum+=arr[cur];
					visite[arr[cur]]=true;
					cur=arr[cur];
					num++;
				}
				moves+=num-1;
				int cp = (num-1)*mn + sum - mn;
				if(mn!=1)
					cp=min(cp, 2*(1+mn) + num-1 + sum -mn);
				price+=cp;

			}
			visite[i]=true;

		}

	}
	//cout<<"->"<<moves-1<<endl;
	//cout<<"->"<<price<<endl;
	ofstream out("output.txt");
	out <<moves<<" "<<price<<endl;


	return 0;
}