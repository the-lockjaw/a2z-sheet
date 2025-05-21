/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat)
{

    vector<int> ans;

    int n = mat.size();
    int m = mat[0].size();

    int top = 0, left = 0, bottom = n - 1, right = m - 1;

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);

        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);

        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);

            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);

            left++;
        }
    }
    return ans;
}