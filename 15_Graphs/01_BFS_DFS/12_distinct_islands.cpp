/*
Problem Statement: Given a grid of size NxM (N is the number of rows and M is the number of columns in the grid) consisting of '0's (Water) and ‘1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/

#include <bits/stdc++.h>
using namespace std;

int dr[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dc[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void dfs(vector<vector<int>> &grid, int sr, int sc)
{
    grid[sr][sc] = 0;
    for (int i = 0; i < 8; i++)
    {
        int nr = sr + dr[i], nc = sc + dc[i];
        if (nc >= 0 && nc < grid[0].size() && nr >= 0 && nr < grid.size() && grid[nr][nc])
            dfs(grid, nr, nc);
    }
}

int num_of_islands(vector<vector<int>> &grid)
{
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j])
            {
                ans++;
                dfs(grid, i, j);
            }

    return ans;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 1}};
    vector<vector<int>> grid2 = {{0, 1, 1, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 0}};
    int ans = num_of_islands(grid);
    cout << "Number of distinct islands = " << ans << endl;
}