// Main idea is to pick the edge with minimum weight that connects a new node

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
	private:
    	vector<int> parent, size;

	public:
	    DisjointSet(int n) {
	        parent.resize(n);
	        size.resize(n, 1);
	        for (int i = 0; i < n; i++)
	            parent[i] = i;
	    }

	    int find_ult_parent(int x) {
	        if (x == parent[x]) return x;
	        return parent[x] = find_ult_parent(parent[x]);
	    }

	    void union_by_size(int u, int v) {
	        int par_u = find_ult_parent(u);
	        int par_v = find_ult_parent(v);
	        if (par_u == par_v) return;

	        if (size[par_u] >= size[par_v]) {
	            parent[par_v] = par_u;
	            size[par_u] += size[par_v];
	        } else {
	            parent[par_u] = par_v;
	            size[par_v] += size[par_u];
	        }
	    }

	    bool connected(int x, int y) {
	        return find_ult_parent(x) == find_ult_parent(y);
	    }
};

int kruskal(int V, vector<vector<int>> adj[])
    {
    	// weight from to
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        // disjoint set
        DisjointSet ds(V);

        // sort by weight
        sort(edges.begin(), edges.end());

        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // if not connected already, then add to graph
            if (ds.find_ult_parent(u) != ds.find_ult_parent(v)) {
                mstWt += wt;
                ds.union_by_size(u, v);
            }
        }

        return mstWt;
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