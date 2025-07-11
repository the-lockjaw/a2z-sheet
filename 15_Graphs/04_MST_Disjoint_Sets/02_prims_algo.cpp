/*
Given a weighted, undirected, and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
(Sometimes it may be asked to find the MST as well, where in the MST the edge-informations will be stored in the form {u, v}(u = starting node, v = ending node)
*/

#include<bits/stdc++.h>
using namespace std;

void print_adj_list(int n, vector<pair<int,int>> adj[]){
	for(int i = 0; i < n; i++){
		for(auto b : adj[i]) 
			cout<<"{"<<b.first<<","<<b.second<<"} ";
		cout<<endl;
	}
	cout<<endl;
}

// i have combined two questions into one
// this function returns both the mst and it's weight.
// {mst,mst_weight} | mst = {u,v} => not storing edge weight in MST.
pair<vector<pair<int,int>>,int> prims(int n, vector<pair<int,int>> adj[]){
	// variables to store the answers
	int mst_weight = 0;
	vector<pair<int,int>> mst;

	// Prim's algorithm starts at a starting node. This can be anything though I have chosen 0.
	int starting_node = 0;

	// Visited Array to prevent loops
	vector<bool> vis(n,false);

	//priority queue to store the edge in form of {weight{parent node, node}}
	priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

	// initialise visited array and priority queue
	vis[starting_node] = true;
	for(auto [node,weight] : adj[starting_node])
		pq.push({weight,{starting_node,node}});

	// core prims
	while(!pq.empty()){
		auto [weight,edge] = pq.top();
		pq.pop();
		auto [parent_node,node] = edge;

		// we pick the edge with least weight that connects a new node
		if(!vis[node]){
			vis[node] = true;
			mst_weight += weight;
			mst.push_back(edge);
		}

		// we push edges of unvisited nodes
		for(auto [x,w]:adj[node])
			if(!vis[x])
				pq.push({w,{node,x}});
	}

	return {mst,mst_weight};
}

int main(){
	int V,E;
	cin>>V>>E;
	vector<pair<int,int>> adj[V];
	for(int i = 0 ; i < E; i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	print_adj_list(V,adj);
	auto [mst, mst_weight] = prims(V,adj);
	cout<<"Weight of MST = "<<mst_weight<<endl;
	cout<<"MST : ";
	for(auto [x,y] : mst)
		cout<<"{"<<x<<","<<y<<"} ";
	cout<<endl;
}

/*
TEST CASE 1
INPUT
5
6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
4 2 7
OUTPUT
Weight of MST = 16
MST : {0,1} {0,3} {1,2} {1,4} 

TEST CASE 2
INPUT
5
6
0 1 2
0 2 1
1 2 1
2 3 2
3 4 1
4 2 2
OUTPUT
5
(0, 2), (1, 2), (2, 3), (3, 4)
*/