/*
542. 01 Matrix
Medium

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 10^4
    1 <= m * n <= 10^4
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/
*/
#include<vector>
#include<queue>
using namespace std;

vector<int> DIR = {0, 1, 0, -1, 0};
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (mat[r][c] == 0) q.emplace(r, c);
            else mat[r][c] = -1; // Marked as not processed yet!

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + DIR[i], nc = c + DIR[i+1];
            if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
            mat[nr][nc] = mat[r][c] + 1;
            q.emplace(nr, nc);
        }
    }
    return mat;
}