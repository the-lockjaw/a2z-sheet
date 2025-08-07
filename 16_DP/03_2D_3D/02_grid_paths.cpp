/*
62. Unique Paths
Medium

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:
    1 <= m, n <= 100
*/
#include<bits/stdc++.h>
using namespace std;

int memo_helper(vector<vector<int>> &dp, int n, int m){
	if( n<0 || m<0 ) return 0;
	if(n==0 || m==0) return dp[n][m] = 1;
	if(dp[n][m]!=-1) return dp[n][m];

	return dp[n][m] = memo_helper(dp,n-1,m) + memo_helper(dp,n,m-1);
}

int grid_paths_memo(int n, int m){
	vector<vector<int>> dp(n,vector<int>(m,-1));
	return memo_helper(dp,n-1,m-1);
}

int grid_paths_tab(int n, int m){
	vector<vector<int>> dp(m,vector<int>(n,-1));

    for(int i = 0; i < m; i++)
        dp[i][0] = 1;
    for(int i = 1; i < n; i++)
        dp[0][i] = 1; 

    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    
    return dp[m-1][n-1];
}

int grid_paths_so(int n, int m){
	vector<int> prev(n,1);
	for(int i = 1; i < m; i++){
		vector<int> temp(n);
		temp[0] = 1;
		for(int j = 1; j < n; j++)
			temp[j] = temp[j-1] + prev[j];
		prev = temp;
	}
	return prev[n-1];
}

// can also be done through maths, (n+m)Cn

int main(){
	int n,m;
	cin>>n>>m;
	int ans_memo = grid_paths_memo(n,m);
	int ans_tab = grid_paths_tab(n,m);
	int ans_so = grid_paths_so(n,m);
	cout << "Memoisation Answer : " << ans_memo << "\n";
	cout << "Tabulation Answer : " << ans_tab << "\n";
	cout << "Space Optimisation Answer : " << ans_so << "\n";
}