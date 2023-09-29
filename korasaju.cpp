#include<bits/stdc++.h>

using namespace std;


array<int, 2*(int)1e5 +1> components={};

array<bool, 2*(int)1e5 +1> visited={}; 

array<vector<int>, 2*(int)1e5 +1> graph,graphT; 

vector<int> ord={-1}; // make one indexed

void dfs(int u, bool transposed=false, int component=-1){
	visited[u]=true;

	auto adj= ( transposed ? graphT[u]: graph[u]);

	for(auto v: adj){
		if(!visited[v]){
			dfs(v,transposed,component);
		}
	}
	if(not transposed){
		ord.push_back(u);
	}
	else{
		components[u]=component;
	}
}

int main(){
	
	ord.reserve(2*(int)1e5+1);

	int n,m;

	cin>>n>>m;

	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graphT[b].push_back(a);
	}

	for(int i=1; i<=n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}

	visited.fill(false);

	int component=0;

	for(int i=n; i>=1; i--){
		if(!visited[ord[i]]){
			//cout<<"OPA\n i:"<<ord[i]<<endl;
			component++;
			dfs(ord[i],true,component);
		}
	}

	vector<int> ids(n+1,0);

	int id=0;

	cout<<component<<endl;

	for(int i=1; i<=n; i++){
		if(not ids[components[i]]){
			ids[components[i]]= ++id;
		}
		cout<<ids[components[i]]<<' ';
	}


	return 0;
}