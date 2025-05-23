/*
81. Search in Rotated Sorted Array II
Medium

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Constraints:
    1 <= nums.length <= 5000
    -1e4 <= nums[i] <= 1e4
    nums is guaranteed to be rotated at some pivot.
    -1e4 <= target <= 1e4
*/
#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return true;

        // Handle duplicates: skip them
        // this is the edge case
        if (nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++;
            right--;
        }
        // Left half is sorted
        else if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid]) // target is in the left half (between mid and left)
                right = mid - 1;                            // search left of mid
            else
                left = mid + 1; // search right of mid
        }
        // Right half is sorted
        else
        {
            if (nums[mid] < target && target <= nums[right]) // target is in right half (between mid and right)
                left = mid + 1;                              // search right of mid
            else
                right = mid - 1; // search left of mid
        }
    }
    return false;
}

int main()
{
    vector<int> q = {2, 5, 6, 0, 0, 1, 2};
    int t = 0;

    if (search(q, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
