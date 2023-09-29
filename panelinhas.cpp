#include<bits/stdc++.h>


using namespace std;

set<int>  nodes_without_component;

array<vector<int>,2*(int)1e5 +1> graph[2];

array<bool,2*(int)1e5 +1> visited[2];  // visited[0|false] -> normal, visited[1|true]->transposto

array<int,2*(int)1e5 +1> components;

int comp=1;

void dfs(int u, bool transposed){

	visited[transposed][u]=true;
	
	for(auto v: graph[transposed][u]){
		if(not visited[transposed][v]){
			dfs(v,transposed);
		}
	}

}

inline void find_component(set<int>::iterator &it){
	while(it!= nodes_without_component.end()){
		if(visited[0][*it] and visited[1][*it]){
			nodes_without_component.erase(it);
			it= nodes_without_component.begin();
			components[*it]=comp;
		}
		else{
			it++;
		}
	}
}

inline void solve(int n){
	
	for(auto  it=nodes_without_component.begin(); it!= nodes_without_component.end(); ){
		if(not visited[0][*it] and not visited[1][*it]){ 
			//cout<< *it<< endl;
			dfs(*it,false);
			dfs(*it,true);
			//cout<< "SAIU DFS\n";
			if(visited[0][*it] and visited[1][*it]){
				find_component(it);
				
			}
			else{
				it++;
				continue;
			}
			comp++;

		}
	}
}



int main(){
	
	int n,m;

	cin>>n>>m; 
	
	for(int i=1; i<=n; i++){
		nodes_without_component.insert(i);
	}

	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		graph[0][a].push_back(b);
		graph[1][b].push_back(a);
	}

	solve(n);

	for(int i=1; i<=n; i++){
		cout<< components[i]<<endl;
	}
	
	return 0;
}	
