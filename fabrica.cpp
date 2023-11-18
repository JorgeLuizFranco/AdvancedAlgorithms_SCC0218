#include<bits/stdc++.h>

using namespace std;

long long dp[(int)1e5+1][11],a[(int)1e5+1][11];

pair<int,int> two_largest(long long arr[], int n) { 
    int first = 1, second = -1; 
    for (int i = 2; i <= n; i++) { 
        if (arr[i] > arr[first]) { 
            second = first; 
            first = i; 
        } 
        else if (arr[i] <= arr[first]) { 
            if (second == -1 || arr[second] < arr[i]) 
                second = i; 
        } 
    } 
    return {first,second}; 
} 

int main(){
	int n,k;

	cin>>n>>k;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			cin>>a[i][j];
		}
	}


	for(int j=1; j<=k; j++){
		dp[1][j]= a[1][j];
		//cout<< dp[1][j]<<endl;
	}

	for(int i=2; i<=n; i++){

		auto[first_max,second_max]= two_largest(dp[i-1],k);

		for(int j=1; j<=k; j++){

			if(j==first_max){
				dp[i][j]= a[i][j]+ dp[i-1][second_max];
			}
			else{
				dp[i][j]= a[i][j]+ dp[i-1][first_max];	
			}
		}
		for(int j=1; j<=k; j++){
			//cout<<"dp["<<i<<"]["<<j<<"] : "<< dp[i][j]<<endl;
		}
	}

	cout<< dp[n][two_largest(dp[n],k).first];

	return 0;
}