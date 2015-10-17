#include <fstream>

using namespace std;

int A[1000000];
int n;

/*
Kadane's algorithm consists of a scan through the array values, computing at each position the maximum (positive sum) subarray ending at that position. 
This subarray is either empty (in which case its sum is zero) or consists of one more element than the maximum subarray ending at the previous position. 
The runtime complexity of Kadane's algorithm is O(n).
*/

int main(){
	
	ifstream in("input.txt");
	in>>n;

	for(int i=0; i<n; i++)
	{
		in>>A[i];
	}

	int mx = -1;
	int mx_here=0;
	for(int i=0; i<n; i++){
		mx_here=max(0,mx_here+A[i]);
		mx=max(mx,mx_here);
	}

	/*for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int tot=0;
			for(int k=i;k<=j;k++)
				tot+=A[k];
			mx=max(mx,tot);
		}
	}*/

	ofstream out("output.txt");
	out<<mx<<endl;

	return 0;
}