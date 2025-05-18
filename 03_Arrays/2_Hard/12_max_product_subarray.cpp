/*
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

Constraints:
    1 <= nums.length <= 2 * 104
    -10 <= nums[i] <= 10
    The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
*/
#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre *= nums[i];
        suff *= nums[nums.size() - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> q = {-2,0,-1};
    int ans = maxProduct(q);
    cout << "Answer = " << ans << endl;
}