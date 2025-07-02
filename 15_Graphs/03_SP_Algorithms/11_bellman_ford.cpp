// SSSP in Directed/Undirected Graph with Negative Weights
// Can identify negative weight cycles
// Main idea is to relax every edge sequentially for n-1 times
// you should have the best paths, try to relax once more, if you can,
// then there is negative edge cycle

#include<bits/stdc++.h>
using namespace std;

void print_adj_list(int v, vector<pair<int,int>> adj_list[]){
	for(int i = 0; i < v; i++){
		cout<<i<<" : ";
		for(auto a : adj_list[i])
			cout<<"{"<<a.first<<","<<a.second<<"} ";
		cout<<endl;
	}
}

vector<int> bellman_ford(int n, vector<pair<int,int>> adj_list[], int src){
	vector<int> dist(n,INT_MAX);
	dist[src] = 0;

	// relax edges for n-1 times
	for(int i = 0; i < n - 1; i++)
		for(int u = 0; u < n; u++)
			for(auto &[v,w] : adj_list[u])
				// remember to handle for integer overflow
				if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
					dist[v] = dist[u] + w;
	
	// check once more to detect -ve edge cycle
	for(int u = 0; u < n; u++)
			for(auto &[v,w] : adj_list[u])
				if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
					return {};

	return dist;			
}

int main(){
	cout<<"BELLMAN FORD ALGORITHM"<<endl;
	cout<<"----------------------"<<endl;
	int V,E;
	cout<<"Enter number of node(s) : ";
	cin>>V;
	cout<<"Enter number of edge(s) : ";
	cin>>E;
	vector<pair<int,int>> adj_list[V];
	for(int i = 0; i < E; i++){
		int u,v,w;
		cout<<"Enter edge "<<i+1<<" (u v w) : ";
		cin>>u>>v>>w;
		adj_list[u].push_back({v,w});
	}
	cout<<endl;
	cout<<"--------------"<<endl;

	cout<<"ADJACENCY LIST"<<endl;
	print_adj_list(V,adj_list);
	cout<<"--------------"<<endl;

	cout<<"ANSWER"<<endl;
	vector<int> ans = bellman_ford(V,adj_list,0);
	if(ans.empty())
		cout<<"Negative Edge Cycle Detected!!!"<<endl;
	else
		for(int i = 0; i < ans.size(); i++){
			cout<<i+1<<" : "<<ans[i]<<endl;
		}
}