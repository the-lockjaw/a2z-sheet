/*
In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.
*/
#include<bits/stdc++.h>
using namespace std;

// int fj_helper(vector<int> &dp, vector<int> &height, int n, int k){
// 	if(n==0)return 0;
// 	if(dp[n]!=-1)return dp[n];

// 	int mini = INT_MAX;

// 	// wrote 'k' instead of 'i' in this loop
// 	// so this is to find minimum cost in all k jumps
// 	for(int i = 1; i <= k; i++){
// 		if(n-i>=0){
// 			int jump_cost = fj_helper(dp,height,n-i,k) + abs(height[n-i]-height[n]);
// 			mini = min(mini,jump_cost);
// 		}
// 	}
// 	return dp[n] = mini;
// }

// int fj_k(vector<int> &height,int n, int k){
// 	vector<int> dp(n,-1);
// 	return fj_helper(dp, height, n-1, k);
// }

int fj_k(vector<int> &height, int n, int k){
	dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1];
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> height(n);
	for(int i= 0; i < n; i++) cin>>height[i];
	int ans = fj_k(height,n,k);
	cout<<"Answer = "<<ans<<"\n";
}