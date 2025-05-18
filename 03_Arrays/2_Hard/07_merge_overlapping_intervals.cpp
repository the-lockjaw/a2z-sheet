/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:
    1 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= starti <= endi <= 10^4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_matrix(vector<vector<int>> v)
{
    for (auto a : v)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // mistake 1 : didn't sort beforehand
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    vector<int> temp = intervals[0];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > temp[1])
        {
            ans.push_back(temp);
            temp = intervals[i];
        }
        else
            // mistake 2 : didn't take max
            temp[1] = max(intervals[i][1], temp[1]);
    }
    ans.push_back(temp);
    return ans;
}

int main()
{
    vector<vector<int>> q = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> r = {{1, 4}, {4, 5}};
    vector<vector<int>> s = {{1, 4}, {0, 4}};
    vector<vector<int>> ans = merge(r);
    print_matrix(ans);
}