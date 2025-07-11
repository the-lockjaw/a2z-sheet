#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
	vector<int> parent,rank;

public:
	DisjointSet(int n){
		rank.resize(n,0);
		parent.resize(n);
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find_ult_parent(int x){
		if(x==parent[x]) return x;
		return parent[x] = find_ult_parent(x); 
	}

	void union_by_rank(int u, int v){
		int par_u = find_ult_parent(u);
		int par_v = find_ult_parent(v);
		if(rank[par_u]==rank[par_v]){
			parent[par_v] = par_u;
			rank[par_u]++;
		}else if(rank[par_u]>rank[par_v]){
			parent[par_v] = par_u;
		}else{
			parent[par_u] = par_v;
		}
	}

	bool connected(int x, int y){
		return find_ult_parent(x)==find_ult_parent(y);
	}
};

int main(){
	int n,e,q;
	cin>>n>>e>>q;
	DisjointSet ds(n);
	for(int i = 0 ; i < e; i++){
		int x,y;
		cin>>x>>y;
		ds.union_by_rank(x,y);
	}
	for(int i = 0 ; i < q; i++){
		int x,y;
		cin>>x>>y;
		if(ds.connected(x,y)) 
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
	}
}