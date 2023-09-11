#include <bits/stdc++.h>

using namespace std;

int n,k,estatuas[(int)1e5+2];

bool f(int r){
	int explosivos=k;

	if(r>estatuas[n-1]){
		return true;
	}

	int atual= estatuas[0],i=1;
	explosivos--;

	while(i<n){
		//cout<< "atual: "<<atual<< " i: "<<i<<" estatuas[i]: "<<estatuas[i]<<" r: "<<r<<" explo: "<<explosivos<<endl;
		if(2*r < estatuas[i]-atual){
			atual=estatuas[i];
			explosivos--;
		}

		i++;
	}
	return explosivos>=0 ;
}	

int main(){
	cin>>n>>k;

	for(int i=0; i<n; i++){
		cin>>estatuas[i];
	}

	int left=0, right= 1e9;

	while(left<right){

		int mid= left+ (right-left)/2;
		if(f(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}

	cout<<right<<endl;

	return 0;

}