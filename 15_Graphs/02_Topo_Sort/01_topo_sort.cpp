// Topological Sort
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print_adj_list(vector<int> adj_list[], int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        cout << i << " : ";
        for (auto a : adj_list[i])
            cout << a << " ";
        cout << endl;
    }
    cout << endl;
}

void dfs(vector<int> adj_list[], stack<int> &st, vector<bool> &visited, int start)
{
    visited[start] = true;
    for (int i = 0; i < adj_list[start].size(); i++)
        if (!visited[adj_list[start][i]])
            dfs(adj_list, st, visited, adj_list[start][i]);
    st.push(start);
}

vector<int> topo_sort(int v, vector<int> adj_list[])
{
    stack<int> st;
    vector<bool> visited(v, false);

    // dfs cuz we need to traverse everything through edges
    for (int i = 0; i < v; i++)
        if (!visited[i])
            dfs(adj_list, st, visited, i);

    // just flipping the stack to return answer in required format
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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
    vector<int> ans = topo_sort(v, adj_list);
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
5 4 3 2 1 0
--------
4
3
1 0
2 0
3 0
---------
3 2 1 0
---------
*/