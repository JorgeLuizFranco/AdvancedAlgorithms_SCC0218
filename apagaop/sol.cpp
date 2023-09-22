#include<bits/stdc++.h>

using namespace std;


int parent[(int)1e5+3], ranki[(int)1e5+10];

void make_set(int v) {
    parent[v] = v;
    ranki[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranki[a] < ranki[b])
            swap(a, b);
        parent[b] = a;
        if (ranki[a] == ranki[b])
            ranki[a]++;
    }
}

vector<tuple<int,int,int>> edges;

int main(){
	int n,m;
	int u,v,c;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		make_set(i);
	}

	while(m--){
		cin>>u>>v>>c;
		edges.push_back({c,u,v});
	}

	sort(edges.begin(), edges.end());
	
	int conexoes=0;
	long long cost=0;

	for(auto[w,u,v]: edges){
		if(find_set(u)!= find_set(v)){
			conexoes++;
			union_sets(u,v);
			cost+= w;
		}
	}
	
	if(conexoes <  n-1){
		cout<< -1 <<endl;
		return 0;
	}

	cout<<cost<<endl;

	return 0;
}
