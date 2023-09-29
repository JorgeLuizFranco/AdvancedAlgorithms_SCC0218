#include<bits/stdc++.h>

using namespace std;

int dp[(int)1e6+1],d[(int)1e6+1];

int n;

int solve(int i){
	if(i>=n-1){
		return d[n];
	}
	
	if(dp[i]!=-1){
		return dp[i];
	}

	return dp[i]= min(abs(d[i]-d[i+1])+solve(i+1),abs(d[i]-d[i+2])+solve(i+2));
}


int main(){

	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>d[i];
		dp[i]=-1;
	}
	
	solve(1);

	cout<<dp[1];

	return 0;
}
