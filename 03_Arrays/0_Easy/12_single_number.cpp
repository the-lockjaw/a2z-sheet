/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
    1 <= nums.length <= 3 * 1e4
    -3 * 1e4 <= nums[i] <= 3 * 1e4
    Each element in the array appears twice except for one element which appears only once.
*/

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int xr = 0;
    for(auto a : nums) xr = xr ^ a;
    return xr;
}

int main(){
    vector<int> q = {2,2,1};
    int ans = singleNumber(q);
    cout<<"The single number is "<<ans<<endl;
}