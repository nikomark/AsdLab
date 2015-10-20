#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//int array[1000000];

vector < pair <int,int> > intervals;

int main(){
	
	int n,a,b;
	
	ifstream in("input.txt");
	in>>n;
	//intervals.resize(n);	
	while(in>>a>>b){
		intervals.push_back(pair <int,int> (a,b));
		//cout<<a<<" "<<b <<endl;
	}

	sort(intervals.begin(), intervals.end());

	/*for(int i=0;i<n;i++){
		cout<<intervals[i].first<<" "<<intervals[i].second<<endl;

	}*/

	int interstart=-1,interend=-1;
	int m=intervals[0].second;

	for(int i=1; i<n; i++)
	{
		if(intervals[i].first-m>interend-interstart)
		{
			interstart=m;
			interend=intervals[i].first;
		}
		m=max(m, intervals[i].second);
	}

	ofstream out("output.txt");

	if (interstart==-1)
		out<<0<<endl;
	else
		out <<interstart<<" "<<interend<<endl;

	return 0;
}