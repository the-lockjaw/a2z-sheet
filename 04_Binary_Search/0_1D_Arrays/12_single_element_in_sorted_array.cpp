/*
540. Single Element in a Sorted Array
Medium

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:

    1 <= nums.length <= 1e5
    0 <= nums[i] <= 1e5
*/
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size(); // size of the array.

    // Edge cases:
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    // MISSED THIS THE FIRST TIME!!!
    // Modify the search space to avoid errors
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        // we are in the right:
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

int main()
{
    vector<int> a = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int single = singleNonDuplicate(a);
    cout << "Single = " << single << endl;
}