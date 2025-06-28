// Kahn's Algorithm (Iterative Topo Sort)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topo_sort_using_kahn(int v, vector<int> adj_list[])
{
    queue<int> q;
    vector<int> indegree(v, 0);
    vector<int> ans;

    // indegree = number of nodes pointing to the node
    for (int i = 0; i < v; i++)
        for (auto a : adj_list[i])
            indegree[a]++;

    // push nodes with 0 indegree into queue
    // also push them into answer as they have to be first
    for (int i = 0; i < v; i++)
        if (!indegree[i])
        {
            q.push(i);
            ans.push_back(i);
        }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // as we remove the node from the graph (it's already in ans vector),
        // we decrease the indegree of every node it was pointing to and
        // repeat the same as above
        for (auto a : adj_list[node])
        {
            indegree[a]--;
            if (!indegree[a])
            {
                q.push(a);
                ans.push_back(a);
            }
        }
    }

    return ans;
}

int main()
{
    int v, e;
    cout << "Enter number of nodes in DAG (0-indexed) : ";
    cin >> v;
    cout << "Enter number of edges in DAG : ";
    cin >> e;
    vector<int> adj_list[v];
    for (int i = 0; i < e; i++)
    {
        cout << "Enter edge " << i + 1 << ": ";
        int x, y;
        cin >> x >> y;
        if (x > v - 1 || y > v - 1 || x < 0 || y < 0)
        {
            cout << "Invalid Node" << endl;
            exit(0);
        }
        adj_list[x].push_back(y);
    }
    vector<int> ans = topo_sort_using_kahn(v, adj_list);
    cout << "Topological Sort : ";
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}
/*
6
6
5 2
2 3
3 1
4 1
4 0
5 0
--------
4 5 2 0 3 1
--------
4
3
1 0
2 0
3 0
---------
1 2 3 0
---------
*/