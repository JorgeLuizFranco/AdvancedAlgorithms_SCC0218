#include<bits/stdc++.h>
#include<climits>

#define visitado(node,mask) ((mask) & (1 << (node)))

using namespace std;

const int inf= numeric_limits<int>::max();

using pii= pair<int,int>;




void dijkstra(int inicio, vector<vector<pii>>& grafo, vector<vector<int>>& dist){

	dist[1][1<<1]=0;


	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

	pq.push({0,inicio, 1<<inicio});

	while(!pq.empty()){

		//cout<<"ou\n";



		auto [d_no, no, mask]= pq.top(); pq.pop();

		if(d_no> dist[no][mask]) continue;

		//cout<< no << ' ' << d_no<<endl;

		for(auto[vertice, peso]: grafo[no]){

			if(visitado(vertice,mask)) continue;

			int vertice_mask = (1<<vertice) | mask ;

			if( d_no + peso< dist[vertice][ vertice_mask ]){

				dist[vertice][vertice_mask]= d_no + peso;

				pq.push({dist[vertice][vertice_mask], vertice, vertice_mask});
			}	

		}

	}

}

int main(){
	
	int n,m,resposta=inf;

	cin>>n>>m;

	vector<vector<pii>> grafo(n+1);	

	//cout<<"A\n";

	while(m--){
		int u,v,d;
		cin>>u>>v>>d;

		grafo[u].push_back({v,d});

		grafo[v].push_back({u,d});

		//cout<<"A\n";

	}

	vector<vector<int>> dist(n+1,vector<int>((1<<(n+1))+1,inf));


	//cout<<"A\n";


	dijkstra(1,grafo,dist);

	

	for(int i=1; i<=n; i++){
		//cout<< i << " : dist[i] -> "<< dist[i][(1<<(n+1))-1-1]<<endl;
		resposta= min(resposta, dist[i][(1<<(n+1))-1-1]);
	}

	cout<<(resposta==inf ? -1 : resposta)<<endl;

	return 0;
}