/*
63. Unique Paths II
Medium

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 10^9.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

Constraints:
    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] is 0 or 1.
*/
#include<bits/stdc++.h>
using namespace std;

// memoisation
int memo_helper(vector<vector<int>> &dp, vector<vector<int>> &grid, int row, int col){
    if(row<0 || col<0) return 0;
    if(grid[row][col] == 1) return dp[row][col] = 0;
    if(row == 0 && col == 0) return dp[row][col] = 1; // &&, not ||
    if(dp[row][col] != -1) return dp[row][col];

    return dp[row][col] = memo_helper(dp,grid,row-1,col) + memo_helper(dp,grid,row,col-1);
}

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows,vector<int>(cols,-1));
    return memo_helper(dp,grid,rows-1,cols-1);
}

// tabulation
int uniquePathsWithObstacles_tab(vector<vector<int>>& grid) {
    if(grid[0][0]) return 0; // DONT FORGET THIS
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows,vector<int>(cols,-1));

    dp[0][0] = 1;
    for(int i = 1; i < rows; i++) dp[i][0] = (grid[i][0]) ? 0 : dp[i-1][0];
    for(int i = 1; i < cols; i++) dp[0][i] = (grid[0][i]) ? 0 : dp[0][i-1];

    for(int i = 1; i < rows; i++)
        for(int j = 1; j < cols; j++)
            dp[i][j] = (grid[i][j]) ? 0 : dp[i-1][j] + dp[i][j-1];

    return dp[rows-1][cols-1];
}

// space optimisation
int space_opt(vector<vector<int>> &grid){
    if(grid[0][0]) return 0; // DONT FORGET THIS
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> dp(cols, 0);
    dp[0] = 1;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                dp[j] = 0;
            } else if(j > 0) {
                dp[j] += dp[j-1];
            }
        }
    }
    
    return dp[cols-1];
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>v[i][j];
    int ans = space_opt(v);
    cout<<ans<<"\n";
}
/*
Test Cases Input

3 3
0 0 0
0 1 0
0 0 0
Expected Output : 2

2 2
0 1
0 0
Expected Output : 1
*/