/*
You are given an m x n integer matrix matrix with the following two properties:
    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -1e4 <= matrix[i][j], target <= 1e4
*/
#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int left = 0;
    int right = matrix.size() - 1;
    int row = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (matrix[mid][0] == target)
        {
            return true;
        }
        else if (matrix[mid][0] < target)
        {
            row = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (row == -1)
        return false;
    else
        return search(matrix[row], target);
}

int main()
{
    vector<vector<int>> q = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 202;
    if (searchMatrix(q, target))

        cout << "true" << endl;
    else
        cout << "false" << endl;
}