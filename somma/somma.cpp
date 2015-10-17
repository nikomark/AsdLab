#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	int n,m;
	ifstream in("input.txt");
	in>>n>>m;
	ofstream out("output.txt");
	out<<n+m<<endl;
	return 0;

}