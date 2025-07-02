// APSP in Directed/Undirected Graph with Negative Weights
// Can detect negative weight cycles
// Main idea: Try to improve distance[i][j] using each vertex k as an intermediate node

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void print_matrix(const vector<vector<int>>& dist){
	int n = dist.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(dist[i][j] == INF)
				cout << "INF ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> floyd_warshall(int n, const vector<tuple<int,int,int>>& edges){
	vector<vector<int>> dist(n, vector<int>(n, INF));

	// Initialize the distance matrix
	for(int i = 0; i < n; i++) dist[i][i] = 0;
	for(auto &[u, v, w] : edges)
		dist[u][v] = min(dist[u][v], w); // handle multiple edges

	// Core Floyd-Warshall algorithm
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(dist[i][k] < INF && dist[k][j] < INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	// Detect negative cycles (i.e., dist[i][i] < 0)
	for(int i = 0; i < n; i++)
		if(dist[i][i] < 0)
			return {}; // Indicates negative weight cycle

	return dist;
}

int main(){
	cout << "FLOYD WARSHALL ALGORITHM" << endl;
	cout << "-------------------------" << endl;
	int V, E;
	cout << "Enter number of node(s) : ";
	cin >> V;
	cout << "Enter number of edge(s) : ";
	cin >> E;
	vector<tuple<int,int,int>> edges;

	for(int i = 0; i < E; i++){
		int u, v, w;
		cout << "Enter edge " << i + 1 << " (u v w) : ";
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}

	cout << endl << "ANSWER (Distance Matrix)" << endl;
	auto dist = floyd_warshall(V, edges);

	if(dist.empty())
		cout << "Negative Edge Cycle Detected!!!" << endl;
	else
		print_matrix(dist);
}