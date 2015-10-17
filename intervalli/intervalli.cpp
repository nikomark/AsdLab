#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int array[1000000];
int main(){
	int n, mx=0;
	ifstream in("input.txt");
	in>>n;
	//fill_n(array,1000000,0);
	for(int i=0; i<n; i++){
		int a,b,cont=0; 
		in>>a>>b;
		cout<<a<<" "<<b <<endl;
		if(mx<a)
			mx=a;
		 if(mx<b)
			mx=b;
		while(a<=b){
			if (array[a]==0){
				array[a]+=a;
				
			}
			a++;
			cont++;
			//cout <<array[cont]<<endl;
		}

	}
	for(int i=0; i<mx+1; i++){
		cout <<array[i]<<endl;
	}
	int left, right, count=0,tmp=0;
	for(int i=1; i<mx+1; i++){
		//cout <<array[i]<<endl;
		if(array[i]==0)
		{
			left= array[i];

			/*while(array[i]==0)
			{
				i++;
				count++;
			}
			right=array[count+1];
		}*/
		//if(tmp<){}
		cout<<left<<" "<<right<<endl;


	}
	
	//cout<<sizeof((array))/sizeof((array[0]));
	//cout<<endl<<mx;
	return 0;
}