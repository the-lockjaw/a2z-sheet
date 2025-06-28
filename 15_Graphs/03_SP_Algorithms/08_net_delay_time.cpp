/*
743. Network Delay Time
Medium

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

Constraints:
    1 <= k <= n <= 100
    1 <= times.length <= 6000
    times[i].length == 3
    1 <= ui, vi <= n
    ui != vi
    0 <= wi <= 100
    All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/
#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>> adj_list[n + 1];
    for(auto& a : times)
        adj_list[a[0]].push_back({a[1], a[2]});

    vector<int> delay(n + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0, k}); // {delay, node}
    delay[k] = 0;

    while(!pq.empty()){
        auto [curr_delay, node] = pq.top();
        pq.pop();

        for(auto& [adj_node, extra_delay] : adj_list[node]){
            int total_delay = curr_delay + extra_delay;
            if(total_delay < delay[adj_node]){
                delay[adj_node] = total_delay;
                pq.push({total_delay, adj_node});
            }
        }
    }

    int ans = *max_element(delay.begin() + 1, delay.end());
    return ans == INT_MAX ? -1 : ans;
}

void runExample(int exampleNum, vector<vector<int>> times, int n, int k, int expected) {
    int result = networkDelayTime(times, n, k);
    cout << "Example " << exampleNum << ":\n";
    cout << "Input: n = " << n << ", k = " << k << ", times = [";
    for (auto& edge : times) {
        cout << "[" << edge[0] << "," << edge[1] << "," << edge[2] << "],";
    }
    cout << "]\n";
    cout << "Output: " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed\n" : "❌ Failed\n");
    cout<<"-----------------------"<<endl;
}

int main() {
    runExample(
        1,
        {{2,1,1},{2,3,1},{3,4,1}},
        4,
        2,
        2
    );

    runExample(
        2,
        {{1,2,1}},
        2,
        1,
        1
    );

    runExample(
        3,
        {{1,2,1}},
        2,
        2,
        -1
    );

    return 0;
}