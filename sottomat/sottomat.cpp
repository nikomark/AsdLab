#include <iostream>
#include <fstream>
using namespace std;
/*
-First calculate thevertical prefix sum for all columns (O(n^2))
-Second, assume that the maximum sub-array will be beetween row a and b, inclusive
	There are O(n^2) a,b pairs such that a<b. This allows us to imagine each 
	collumn sum as an sum of one dimensional arrray across all columns
-----------
Dynamic programming uses aditional memory to save computatuion time; it serves an example of time-memory trade-of.

1)top-down with memoization:
we write the procedure recursively in natural manner, but modified to save the result of each subproblem(array or hashtable)
The procedure first cheacks to see whater it  has previously solved this subproblem. if so it reeturnes the saved value, saving further
computation at this level; if not the procedure computes the value in usual manner. We say that the recursive procedure has been memoized;
it "remembers" what result it has computed previously..

2)buttom-up method: 
this approch typically depends on some natural notion of the "size" of a subproblem, such that solving any particular subproblem 
depends only on solving "smaller" subproblems.we sort the subproblems by size and solve them in size order, smallest first. 
when solving a particular subproblem, we have saved their solution. We solve each subproblem only once, and when we first see it, we 
have already solved all of its prerequisite subproblems.

*/
//int r,c;
int kadane(int[],int);
//void print(int, int);

int inMat[200][200];

int main(){
 	
 	int r,c;
	ifstream in("input.txt");
	in>>r>>c;
	//int mat[r][c];
	//read matrix from file
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			in>>inMat[i][j];	
		}
	}
	
	//print(r,c);
	//int sumMat[r][c]={{0}};

	//int left=0, right=0;
	
	int maxSum=0;

	for (int left 	= 0; left <= c; left++)
	{
		int tmp[r];
		std::fill_n(tmp, r, 0);

		for (int right = left; right < c; right++)
		{
			for(int i=0; i<r; i++)
			{
				tmp [i]+=inMat[i][right];

			}
			int sum = kadane(tmp,r); 
			if (sum>maxSum)
				maxSum=sum;
		}
	}

	ofstream out("output.txt");

	out<<maxSum<<endl;

	return 0;
}

int kadane(int A[], int n ){
	int mx=-1;
	int mx_here=0;

	for (int i = 0; i < n; ++i)
	{
		mx_here=max(0,mx_here+A[i]);
		mx=max(mx,mx_here);
	}
	return mx;
}

/*void print(int r, int c){

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout<<inMat[i][j]<<"\t";
		}
		cout<<endl;
	}
}*/