/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

Constraints:
    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

Follow up: Could you minimize the total number of operations done?
*/
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v)
{
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}

void moveZeroes(vector<int> &a)
{
    int n = a.size();
    int j = -1;
    // place the pointer j:
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    // no non-zero elements:
    if (j == -1)
        return;

    // Move the pointers i and j
    // and swap accordingly:
    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    print_vector(nums);
}