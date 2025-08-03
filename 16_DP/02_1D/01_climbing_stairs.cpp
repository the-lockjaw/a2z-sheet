#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& dp, int n) {
    if (n <= 1)
        return dp[n] = n + 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = solve(dp, n - 1) + solve(dp, n - 2);
}

int climbStairsMemoization(int n) {
    vector<int> steps(n, -1);
    return solve(steps, n - 1);
}

int climbStairsTabulation(int n){
	int prev2 = 1, prev = 1;
    for(int i = 2; i <= n; i++){
        int ans = prev2 + prev;
        prev2 = prev;
        prev = ans;
    }
    return prev;
}

int main(){
	int n;
	cin>>n;
	int ans1 = climbStairsTabulation(n);
	int ans2 = climbStairsMemoization(n);
	cout<<"Tabulation Answer = "<<ans1<<"\n";
	cout<<"Memoization Answer = "<<ans2<<"\n";
}