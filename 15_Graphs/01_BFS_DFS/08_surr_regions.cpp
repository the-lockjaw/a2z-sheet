/*
130. Surrounded Regions
Medium

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:
Input: board = [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]
Output: [['X','X','X','X'],['X','X','X','X'],['X','X','X','X'],['X','O','X','X']]

Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:
Input: board = [['X']]
Output: [['X']]

Constraints:
    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.
*/

#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<char>> &board)
{
    for (auto a : board)
    {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'O' && (i == 0 || i == m - 1 || j == 0 || j == n - 1))
            {
                board[i][j] = '#';
                q.push({i, j});
            }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || board[nx][ny] == 'X')
                continue;
            else
            {
                board[nx][ny] = '#';
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
}

int main()
{
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board2 = {{'O', 'O'}, {'O', 'O'}};

    cout << "Initial : " << endl;
    print_matrix(board2);

    solve(board);
    cout << "Final : " << endl;
    print_matrix(board2);
}