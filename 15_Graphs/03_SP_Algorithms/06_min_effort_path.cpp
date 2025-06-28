/*
1631. Path With Minimum Effort
Medium

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

Constraints:
    rows == heights.length
    columns == heights[i].length
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 10^6
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<limits.h>
using namespace std;

// just a variation of Dijkshtra
int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();

    // keeps track of best effort so that we don't traverse again with worse effort
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    while (!pq.empty()) {
    	// IMPORTANT : priority_queue has .top() not .front()
    	// Why? Because it's a heap
        auto [effort, coord] = pq.top();
        auto [r, c] = coord;
        pq.pop();

        // if reached destination then return
        // min effort is ensured due to priority queue
        if (r == rows - 1 && c == cols - 1) return effort;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                int new_effort = abs(heights[nr][nc] - heights[r][c]);
                int total_effort = max(effort, new_effort);

                // if worse effort then discard, otherwise push into pq
                if (total_effort < dist[nr][nc]) {
                    dist[nr][nc] = total_effort;
                    pq.push({total_effort, {nr, nc}});
                }
            }
        }
    }

    return -1;
}


int main(){
	vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
	vector<vector<int>> heights2 = {{1,2,3},{3,8,4},{5,3,5}};
	int ans = minimumEffortPath(heights2);
	cout<<"Minimum Effort = "<<ans<<endl;
}