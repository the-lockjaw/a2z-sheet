/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
    1 <= nums.length <= 2 * 1e4
    -1000 <= nums[i] <= 1000
    -1e7 <= k <= 1e7
*/
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int sum = 0;
    unordered_map<int, int> mp;
    int ans = 0;
    mp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        ans += mp[sum - k];
        mp[sum]++;
    }
    return ans;
}

int main()
{
    vector<int> q = {1, 1, 1};
    int k = 2;
    int ans = subarraySum(q, k);
    cout << "Answer = " << ans << endl;
}