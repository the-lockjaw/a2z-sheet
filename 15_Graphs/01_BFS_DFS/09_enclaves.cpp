/*
1020. Number of Enclaves
Medium

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 500
    grid[i][j] is either 0 or 1.
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int sr, int sc)
{
    int m = grid.size();
    int n = grid[0].size();

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int nr = sr + dr[i], nc = sc + dc[i];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n || !grid[nr][nc])
            continue;
        grid[nr][nc] = 0;
        dfs(grid,nr,nc);
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == 1)
            dfs(grid, 0, i);
        if (grid[m - 1][i] == 1)
            dfs(grid, m - 1, i);
    }

    for (int i = 1; i < m - 1; i++)
    {
        if (grid[i][0] == 1)
            dfs(grid, i, 0);
        if (grid[i][n - 1] == 1)
            dfs(grid, i, n - 1);
    }
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    int ans = numEnclaves(grid);
    cout << "Answer = " << ans << endl;
}