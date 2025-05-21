/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:
    1 <= nums.length <= 1e4
    -1e4 <= nums[i] <= 1e4
    nums contains distinct values sorted in ascending order.
    -1e4 <= target <= 1e4
*/
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    if (target < nums[0])
    {
        return 0;
    }

    if (target > nums[nums.size() - 1])
    {
        return nums.size();
    }

    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            ans = mid;
            right = mid - 1;
        }
        else

            left = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> q = {1, 3, 5, 6};
    int t = 0;
    int ans = searchInsert(q, t);
    cout << "Answer = " << ans << endl;
}