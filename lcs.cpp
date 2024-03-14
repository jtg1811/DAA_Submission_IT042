#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s1="abc";
    string s2 = "aec";
    clock_t start,end;
	start = clock();
	int ans = lcs(s1,s2);
	end = clock();
	float time = float(end-start)/(float)CLOCKS_PER_SEC;
	cout<<endl<<time;
    cout<<endl<<ans;
	return 0;
    
}