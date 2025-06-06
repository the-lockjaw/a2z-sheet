/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.

Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).

Example 2:
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44

Constraints:
    1 <= nums.length <= 5 * 1e4
    1 <= nums[i] <= 1e6
    nums.length <= threshold <= 1e6
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

bool check(vector<int> &nums, int th, int x)
{
    int result = 0;
    for (auto a : nums)
    {
        result += a / x;
        if (a % x)
            result++;
    }
    return result <= th;
}

int find_max(vector<int> v)
{
    int max = INT_MIN;
    for (auto a : v)
        if (a > max)
            max = a;
    return max;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int left = 1;
    int right = find_max(nums);
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(nums, threshold, mid))
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> q = {44, 22, 33, 11, 1};
    int threshold = 5;
    int ans = smallestDivisor(q, threshold);
    cout << "Answer = " << ans << endl;
}