/*
198. House Robber
Medium
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 400
*/

#include<bits/stdc++.h>
using namespace std;

// MEMOIZATION
// int rob_helper(int idx, vector<int>& nums, vector<int>& dp) {
// 	if(idx < 0) return 0;
// 	if(dp[idx] != -1) return dp[idx];

// 	int pick = nums[idx] + rob_helper(idx - 2, nums, dp);
// 	int skip = rob_helper(idx - 1, nums, dp);

// 	return dp[idx] = max(pick, skip);
// }

// int rob(vector<int>& nums) {
// 	int n = nums.size();
// 	vector<int> dp(n, -1);
// 	return rob_helper(n - 1, nums, dp);
// }

// TABULATION
// int rob(vector<int>& nums) {
// 	int n = nums.size();
// 	if(n == 0) return 0;
// 	if(n == 1) return nums[0];

// 	vector<int> dp(n);
// 	dp[0] = nums[0];
// 	dp[1] = max(nums[0], nums[1]);

// 	for(int i = 2; i < n; i++)
// 		dp[i] = max(dp[i-1], nums[i] + dp[i-2]);

// 	return dp[n-1];
// }

// SPACE OPTIMISATION
int rob(vector<int>& nums) {
	int n = nums.size();
	if(n == 0) return 0;
	if(n == 1) return nums[0];

	int prev2 = nums[0];
	int prev1 = max(nums[0], nums[1]);

	for(int i = 2; i < n; i++) {
		int curr = max(prev1, nums[i] + prev2);
		prev2 = prev1;
		prev1 = curr;
	}

	return prev1;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin>>nums[i];
	int ans = rob(nums);
	cout<<"Answer = "<<ans<<"\n";
}

/*
4
1 2 3 1

5
2 7 9 3 1
*/