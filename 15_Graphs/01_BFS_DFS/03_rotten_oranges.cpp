/*
994. Rotting Oranges
Medium

You are given an m x n grid where each cell can have one of three values:
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.



Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print_matrix(vector<vector<int>> v)
{
    for (auto a : v)
    {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

void print_pair_queue(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        pair<int, int> a = q.front();
        q.pop();
        cout << a.first << " " << a.second << endl;
    }
    cout << endl;
}

/*
MY SOLUTION:

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // visited matrix
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // queue for bfs, pair to store x and y coordinate
    queue<pair<int, int>> q;

    // if this comes doesn't come back to zero then answer is -1
    int fresh_oranges = 0;

    // number of passes in bfs (or levels in like trees)
    int minutes = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
            else if (grid[i][j] == 1)
                fresh_oranges++;
            else
                visited[i][j] = true;
        }
    }

    // put (-1,-1) for level break
    q.push(make_pair(-1, -1));

    while (!q.empty())
    {
        // take out the first rotten orange
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // if x == y == -1, then we have processed the oranges for a minute.
        if (x == -1)
        {
            minutes++;
            // if q is not empty then we will need at least another minute to process it
            if (!q.empty())
                q.push(make_pair(-1, -1));
            continue;
        }

        // rot all oranges adjacent to the current one (if they are not rotten already)
        if (x != 0 && (!visited[x - 1][y]))
        {
            visited[x - 1][y] = true;
            q.push(make_pair(x - 1, y));
            fresh_oranges--;
        }

        if (x != m - 1 && (!visited[x + 1][y]))
        {
            visited[x + 1][y] = true;
            q.push(make_pair(x + 1, y));
            fresh_oranges--;
        }

        if (y != 0 && (!visited[x][y - 1]))
        {
            visited[x][y - 1] = true;
            q.push(make_pair(x, y - 1));
            fresh_oranges--;
        }

        if (y != n - 1 && (!visited[x][y + 1]))
        {
            visited[x][y + 1] = true;
            q.push(make_pair(x, y + 1));
            fresh_oranges--;
        }
    }

    return fresh_oranges ? -1 : minutes - 1;
}
*/

// Striver's Solution
// Same logic but cleaner code
int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;

    int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;

    queue<pair<int, int>> rotten;
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] != 0)
                tot++;
            if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!rotten.empty())
    {
        int k = rotten.size();
        cnt += k;
        while (k--)
        {
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        if (!rotten.empty())
            days++;
    }

    return tot == cnt ? days : -1;
}

int main()
{
    vector<vector<int>> q = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    vector<vector<int>> r = {{2, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> s = {{0, 2}};

    int ans1 = orangesRotting(q);
    cout << ans1 << endl;

    int ans2 = orangesRotting(r);
    cout << ans2 << endl;

    int ans3 = orangesRotting(s);
    cout << ans3 << endl;
}