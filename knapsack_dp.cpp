#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int W, int wt[], int val[], int n) 
{ 

	if (n == 0 || W == 0) 
		return 0; 

	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1); 

	// Return the maximum of two cases: 
	// (1) nth item included 
	// (2) not included 
	else
		return max( 
			val[n - 1] 
				+ knapSack(W - wt[n - 1], wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
} 

int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 

	int n = sizeof(profit) / sizeof(profit[0]);
	clock_t start,end;
	start = clock();
	int ans = knapSack(W, weight, profit, n);
	end = clock();
	float time = float(end-start)/(float)CLOCKS_PER_SEC;
	cout<<endl<<"Time : "<<time<<endl<<ans;  
	return 0; 
}
