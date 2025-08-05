/*
Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/

#include<bits/stdc++.h>
using namespace std;

int frog_jump_helper(vector<int> &dp, vector<int> &heights, int idx){
	if(idx == 0)return dp[0] = 0;
	if(idx == 1)return dp[1] = heights[1] - heights[0];
	if(dp[idx]!=-1)return dp[idx];

	return dp[idx] = min(frog_jump_helper(dp,heights,idx-1) + abs(heights[idx]-heights[idx-1]), frog_jump_helper(dp,heights,idx-2) + abs(heights[idx]-heights[idx-2]));
}

int frog_jump_memo(vector<int> &heights){
	vector<int> dp(heights.size(),-1);
	return frog_jump_helper(dp,heights,heights.size()-1);
}

int frog_jump_tab(vector<int> &heights){
	int n = heights.size();
	vector<int> dp(n,-1);
	dp[0] = 0;
	dp[1] = abs(heights[1]-heights[0]);
	for(int i = 2; i < n; i++){
		dp[i] = min(dp[i-1]+abs(heights[i]-heights[i-1]),dp[i-2]+abs(heights[i]-heights[i-2]));
	}
	return dp[n-1];
}

// space optimisation
int frog_jump_so(vector<int> &heights){
	int prev2 = 0;
	int prev1 = abs(heights[1]-heights[0]);
	int n = heights.size();
	if(n==1)return prev2;
	if(n==2)return prev1;
	for(int i = 2; i < n; i++){
		int ans2 = prev2 + abs(heights[i]-heights[i-2]);
		int ans1 = prev1 + abs(heights[i]-heights[i-1]);
		int ans = min(ans1,ans2);
		prev2 = prev1;
		prev1 = ans;
	}
	return prev1;
}

int main(){
	int n;
	cin>>n;
	vector<int> heights(n);
	for(int i = 0; i < n; ++i) cin >> heights[i];
	int ans = frog_jump_so(heights);
	cout<<"Answer = "<<ans;
}