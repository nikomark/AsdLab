
/*Merge Sort divide il vettore in sequenze di n/2 elementi ciascuno,
ordina ciascuna sequenza e poi fonde le parti ottenute in un' unica
sequenza ordinata. Per fondere: procedura merge() che utilizza il vettore
di appoggio B (globale).Fa uso di 3 indici per scandire A[primo ..mezzo]
B[primo...ultimo]. Complessità di Merge() è O(n), complessità di MergeSort()
è O(nlogn). T(n)= 2T(n/2)+dn per n<=2, T(n)=c per n=1.*/

#include <iostream>
#include <fstream>

using namespace std;

int B[1000000];

void mergeSort(int [], int, int);
void merge(int [], int, int, int);

int main(){

	int N;
	int A[1000000];
	//read input from file
	ifstream in("input.txt");
	in>>N;

	for(int i=0; i<N; i++)
	{
		in>>A[i];
	}
	//rec call
	mergeSort(A,0,N-1);
	//write on ordered array on file
	ofstream out("output.txt");
	for(int i=0; i<N; i++){
		out <<A[i]<<" ";
	}
	out<<endl;
	
	return 0;
}

void mergeSort(int A[], int first, int last){
	
	if(first < last){
		int middle = (first+last)/2;
		mergeSort(A, first, middle);
		mergeSort(A, middle+1, last);
		merge(A, first, last, middle);
	}
}

void merge(int A[], int first, int last, int middle){
	
	int i,j,k;
	i= first;
	j= middle+1;
	k= 0;

	while(i<=middle && j<= last){

		if(A[i]<A[j]){
			B[k++]=A[i++];
		}
		else{
			B[k++]=A[j++];
		}
	}
	
	while(i<=middle){
		B[k++]=A[i++];
	}
	while(j<=last){
		B[k++]=A[j++];
	}
	
	for(i=0, j=first; j<=last; A[j++]=B[i++]);
}