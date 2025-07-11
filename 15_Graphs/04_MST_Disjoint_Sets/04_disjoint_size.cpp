#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
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

int main() {
    int n, e, q;
    cin >> n >> e >> q;
    DisjointSet ds(n);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        ds.union_by_size(x, y);
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << (ds.connected(x, y) ? "Yes" : "No") << endl;
    }
}
