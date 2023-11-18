#include<bits/stdc++.h>

#define maxw ((int)1e5 +2)

using namespace std;


long long valor[102];


int peso[maxw];

int main(){
	int n,w;

	cin>>n>>w;

	for(int i=1; i<=n; i++){
		cin>>peso[i]>>valor[i];
	}

	vector<long long> atual(maxw),anterior(maxw);

	for(int i=2; i<=n+1; i++){
		anterior= atual;
		for(int p=w; p>=0; p--){
			if(p>=peso[i-1] and anterior[p-peso[i-1]]+valor[i-1]>anterior[p]){
				atual[p]= anterior[p-peso[i-1]]+valor[i-1];
			}
		}
	}

	cout<<atual[w]<<endl;

	return 0;

}