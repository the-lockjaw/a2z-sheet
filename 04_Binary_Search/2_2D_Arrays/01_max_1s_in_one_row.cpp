/*
You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int first_occurence(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int ans = nums.size();
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int max_ones(vector<vector<int>> &nums, int n, int m)
{
    int ans = -1;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "For index = " << i << endl;
        int ones = m - first_occurence(nums[i], 1);
        cout << "Ones = " << ones << endl;
        if (ones > max)
        {
            ans = i;
            max = ones;
        }
        cout << endl;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> q(n, vector<int>(m));
    for (vector<int> &a : q)
        for (int &b : a)
            cin >> b;

    int ans = max_ones(q, n, m);
    cout << "Answer = " << ans << endl;
}