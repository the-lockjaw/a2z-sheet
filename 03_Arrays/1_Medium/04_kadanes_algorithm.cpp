/*
KADANE'S ALGORITHM
Given an integer array nums, find the with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int ans = nums[0];
    int temp_max = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (temp_max < 0)
        {
            temp_max = 0;
        }
        temp_max += nums[i];
        if (temp_max > ans)
        {
            ans = temp_max;
        }
    }
    return ans;
}

int main()
{
    vector<int> q = {1};
    int ans = maxSubArray(q);
    cout << "Maximum subarray = " << ans << endl;
}