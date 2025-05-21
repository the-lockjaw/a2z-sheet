/*
You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/
#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> v, int x)
{
    int left = 0;
    int right = v.size() - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] <= x)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return v[ans];
}

int ceil(vector<int> v, int x)
{
    int left = 0;
    int right = v.size() - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] >= x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return v[ans];
}

int main()
{
    vector<int> q = {3, 4, 4, 7, 8, 10};
    int x = 8;
    cout << "Floor = " << floor(q, x) << endl;
    cout << "Ceil = " << ceil(q, x) << endl;
}