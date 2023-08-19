#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> palestras;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int l,r;
		cin>>l>>r;
		palestras.push_back({r,l});
	}
	sort(palestras.begin(),palestras.end());

	int cont=0;

	int r_prev=0;
	for(int i=0; i<n; i++){
		auto[r,l]=palestras[i];
		if(l>=r_prev){
			cont++;
			r_prev=r;
		}
	}
	cout<<cont<<endl;
	return 0;
}