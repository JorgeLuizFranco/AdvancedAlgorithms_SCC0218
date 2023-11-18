#include<bits/stdc++.h>

using namespace std;

void solve(long long k, map<long long,char> &values) 
{ 
    vector<bool> prime(k+1,true);
    
    
  
    for (long long p = 2; p * p <= k; p++) { 
        if (prime[p] == true) { 
            for (long long i = 2 * p ; i <= k; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (long long i = 2; i <= k; i++){ 
    	//cout<<i*i<<endl;
        if (prime[i] and values.find(i*i)!=values.end()){
        	//cout<<"ou\n";
        	//cout<<i<<' '<<i*i<<endl;
        	values[i*i]='1';
        } 
    }
            
} 

int main(){

	map<long long,char> values;

	vector<long long> vals;

	int n;

	cin>>n;

	vals.reserve(n);


	for(int i=1; i<=n; i++){
		long long x;
		cin>>x;
		values[x]='0';
		vals.push_back(x);

	}

	
	solve((long long)1e6 *10,values);


	for(long long x: vals){
		
		cout<< (values[x]=='0' ? 0 : 1);
	}

	return 0;

}