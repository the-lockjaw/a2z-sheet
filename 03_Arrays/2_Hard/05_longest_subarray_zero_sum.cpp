/*
Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Examples
-------------------------------------
Example 1:
Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result: 5
Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!

Example 2:
Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result: 8
Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
Length of longest subarray = 8

Example 3:
Input Format: N = 3, array[] = {1, 0, -5}
Result: 1
Subarray : {0}
Length of longest subarray = 1

Example 4:
Input Format: N = 5, array[] = {1, 3, -5, 6, -2}
Result: 0
Subarray: There is no subarray that sums to zero
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void print_map(map<int, int> mp)
{
    for (auto a : mp)
    {
        cout << a.first << " " << a.second << endl;
    }
}

int length_of_largest_subarray_with_zero_sum(vector<int> nums)
{
    // basic idea to maintain an array which tells us the sum of elements from the start to the given index, if any two sums are same, then the sum of elements between them is 0
    map<int, int> prefix_sum;
    int ans = 0;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == 0)
        {
            ans = i + 1;
            continue;
        }

        if (prefix_sum.find(sum) != prefix_sum.end())
        {
            ans = max(ans, i - prefix_sum.find(sum)->second);
        }
        else
        {
            prefix_sum[sum] = i;
        }
    }

    return ans;
}

int main()
{
    vector<int> q = {1, 3, -5, 6, -2};
    int ans = length_of_largest_subarray_with_zero_sum(q);
    cout << "Answer = " << ans << endl;
}