// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. (using DFS)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print_list(int n, vector<int> list[])
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " : ";
        for (auto a : list[i])
            cout << a + 1 << " ";
        cout << endl;
    }
    cout << endl;
}

bool detect(int src, vector<int> adj[], vector<int> &vis)
{
    stack<pair<int,int>> st;
    vis[src] = 1;
    st.push({src,-1});

    while (!st.empty())
    {
        int node = st.top().first;
        int parent = st.top().second;
        st.pop();

        for (auto adj_node : adj[node])
        {
            if(!vis[adj_node]){
                vis[adj_node] = true;
                st.push({adj_node,node});
            }else{
                if(parent!=adj_node){
                    return true;
                }
            }
        }
    }

    // there's no cycle
    return false;
}

bool is_cyclic(int n, int e, vector<int> adj_list[])
{
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj_list, vis))
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Cycle Detection for Undirected 1-indexed graph" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter number of node(s): ";
    cin >> n;
    cout << endl;
    int e;
    cout << "Enter number of edge(s): ";
    cin >> e;
    cout << endl;
    vector<int> adj_list[n];
    for (int i = 0; i < e; i++)
    {
        int v, u;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> v >> u;
        if(v>n||u>n){
            cout<<"Invalid Node Index!"<<endl;
            return 1;
        }
        // convert to 0-indexed graph
        adj_list[v - 1].push_back(u - 1);
        adj_list[u - 1].push_back(v - 1);
    }

    cout << "Adjacency List : " << endl;
    print_list(n, adj_list);

    bool ans = is_cyclic(n, e, adj_list);
    if (ans)
        cout << "the graph is cyclic" << endl;
    else
        cout << "the graph is NOT cyclic" << endl;
    cout << "----------------------------------------------" << endl;
}
/*
8 7 1 2 1 3 2 5 2 6 3 4 3 7 7 8
*/