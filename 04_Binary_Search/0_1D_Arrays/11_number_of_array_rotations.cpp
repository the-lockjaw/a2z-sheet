/*
Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Example 2:
Input Format: arr = [3,4,5,1,2]
Result: 3
Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.
*/

#include <bits/stdc++.h>
using namespace std;

// same as min in rotated sorted array but we return index instead of the value
// OBS: the number of rotations = index of minimum element
int no_of_rotations(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            if (ans > arr[low])
            {
                ans = arr[low];
                index = low;
            }

            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (ans > arr[low])
            {
                ans = arr[low];
                index = low;
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    int ans = no_of_rotations(arr);
    cout << "The number of rotations is : " << ans << "\n";
    return 0;
}
