#include<bits/stdc++.h>

using namespace std;



int main(){
	int n,k;
	cin>>n>>k;
	int l,cont=0;
	int estat;
	cin>>estat;
	l=estat;

	++cont;
	for(int i=1; i<n; i++){
		
		cin>> estat;

		if(estat-l > 2*k){
			l=estat;
			++cont;
		}	

	}

	cout<< cont<<endl;
	return 0;
}