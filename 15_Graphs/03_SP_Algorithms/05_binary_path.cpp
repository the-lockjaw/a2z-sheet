/*
091. Shortest Path in Binary Matrix
Medium

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
*/
#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> &grid)
{
    for (auto a : grid)
    {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[0][0] || grid[rows - 1][cols - 1])
        return -1;

    vector<vector<int>> dist(rows, vector<int>(cols, -1));

    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0, 0});

    int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !grid[nr][nc])
            {
                int new_distance = dist[r][c] + 1;
                if (dist[nr][nc] == -1 || dist[nr][nc] > new_distance)
                {
                    q.push({nr, nc});
                    dist[nr][nc] = new_distance;
                }
            }
        }
    }

    return dist[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    vector<vector<int>> grid2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    vector<vector<int>> grid3 = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    vector<vector<int>> grid4 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};

    int ans = shortestPathBinaryMatrix(grid4);
    cout << "Answer = " << ans << endl;
}