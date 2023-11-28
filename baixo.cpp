#include<bits/stdc++.h>

using namespace std;

long long dp[(int)1e6+1];

long long d[(int)1e6+1];

int n;

long long solve(int i){
	//cout<< "i: "<<i<<" dp[i]:"<< dp[i]<<endl;
	if(i==n){
		return 0;
	}

	if(dp[i]!=-1){
		return dp[i];
	}
	//cout<< "i: "<<i<<" dp[i]:"<< dp[i]<<endl;

	if(i==n-1){
		return dp[i]= abs(d[i]-d[i+1]);
	}
	//cout<< "i: "<<i<<" dp[i]:"<< dp[i]<<endl;

	if(i==n-2){
		return dp[i]= min(abs(d[i]-d[i+1])+solve(i+1),abs(d[i]-d[i+2]));
	}
	//cout<< "i: "<<i<<" dp[i]:"<< dp[i]<<endl;

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
