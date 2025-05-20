/*
Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
*/
#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int> &nums, int x)
{
    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= x)
        {
            // if satisfies then store the answer and move backwards in search of a better one
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> q = {3, 5, 8, 15, 19};
    int x = 9;
    int ans = lower_bound(q, x);
    cout << "Answer = " << ans << endl;
}