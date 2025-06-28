#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <set>
using namespace std;

vector<int> dijkstra(int start_node, const vector<vector<pair<int, int>>> &adj_list)
{
    int n = adj_list.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[start_node] = 0;

    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        int min_dist = INT_MAX;

        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;
        visited[u] = true;

        for (const auto &[v, weight] : adj_list[u])
        {
            if (!visited[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    return dist;
}

vector<int> dijkstra_pq(int start_node, vector<vector<pair<int, int>>> adj_list)
{
    int n = adj_list.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node}); // {distance, node}

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u])
            continue; // Skip outdated entry

        for (auto edge : adj_list[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

vector<int> dijkstra_set(int start_node, const vector<vector<pair<int, int>>> &adj_list)
{
    int n = adj_list.size();
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> s; // {distance, node}

    dist[start_node] = 0;
    s.insert({0, start_node});

    while (!s.empty())
    {
        auto [current_dist, u] = *s.begin();
        s.erase(s.begin());

        for (const auto &edge : adj_list[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                // Remove if v already exists with old distance
                if (dist[v] != INT_MAX)
                {
                    s.erase({dist[v], v});
                }
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }

    return dist;
}

/*
| Feature                | Naive           | Priority Queue    | Set                                    |
| ---------------------- | --------------- | ----------------- | -------------------------------------- |
| Time Complexity        | O(V² + E)       | O((V + E) log V)  | O((V + E) log V)                        |
| Decrease-key Support   | ✅              | ❌               | ✅                                      |
| Best for               | Dense graphs    | Sparse graphs    | Sparse graphs + decrease-key            |
| Heap update efficiency | N/A             | ❌               | ✅                                      |
| Ease of implementation | simple          | standard         | slightly more code                      |
| Library requirement    | None            | <queue>          | <set>                                   |
| Overall performance    | Slow for large  | Best general case| ⚠️ Slightly slower in practice than PQ  |
*/

int main()
{
    int n, m;
    cout << "Enter number of nodes (n): ";
    cin >> n;

    cout << "Enter number of edges (m): ";
    cin >> m;

    vector<vector<pair<int, int>>> adj_list(n);

    cout << "Enter " << m << " edges in format: u v weight (0-indexed nodes):\n";
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].emplace_back(v, w);
        adj_list[v].emplace_back(u, w);
    }

    int start_node;
    cout << "Enter start node (0-indexed): ";
    cin >> start_node;

    vector<int> distances = dijkstra(start_node, adj_list);

    cout << "\nShortest distances from node " << start_node << ":\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "To node " << i << ": ";
        if (distances[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << distances[i] << "\n";
    }

    return 0;
}
