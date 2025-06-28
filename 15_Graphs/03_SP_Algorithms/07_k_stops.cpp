/*
787. Cheapest Flights Within K Stops
Medium

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

Constraints:
    1 <= n <= 100
    0 <= flights.length <= (n * (n - 1) / 2)
    flights[i].length == 3
    0 <= fromi, toi < n
    fromi != toi
    1 <= pricei <= 104
    There will not be any multiple flights between two cities.
    0 <= src, dst, k < n
    src != dst
*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // stops cost node
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,src}});

    vector<int> dist(n,INT_MAX);
    vector<pair<int,int>> adj_list[n];

    for(auto a : flights){
    	adj_list[a[0]].push_back({a[1],a[2]});
    }

    while(!q.empty()){
    	auto [stops, x] = q.front();
    	auto [cost, node] = x;
    	q.pop();

    	if(stops > k) continue;

    	for(auto a : adj_list[node]){
    		int adj_node = a.first;
    		int extra = a.second;
    		int total_cost = cost + extra;
    		if(total_cost<dist[adj_node]){
    			dist[adj_node] = total_cost;
    			q.push({stops+1,{total_cost,adj_node}});
    		}
    	}
    }

    if(dist[dst]==INT_MAX)return -1;
    else return dist[dst];
}


void runExample(int exampleNum, int n, vector<vector<int>> flights, int src, int dst, int k, int expected) {
    cout << "Example " << exampleNum << ":\n";
    cout << "Input: n = " << n << ", src = " << src << ", dst = " << dst << ", k = " << k << "\n";
    int result = findCheapestPrice(n, flights, src, dst, k);
    cout << "Output: " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed\n" : "❌ Failed\n");
    cout<<"----------------------------"<<endl;
}

int main() {
    // Example 1
    runExample(
        1,
        4,
        {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}},
        0,
        3,
        1,
        700
    );

    // Example 2
    runExample(
        2,
        3,
        {{0,1,100},{1,2,100},{0,2,500}},
        0,
        2,
        1,
        200
    );

    // Example 3
    runExample(
        3,
        3,
        {{0,1,100},{1,2,100},{0,2,500}},
        0,
        2,
        0,
        500
    );

    return 0;
}