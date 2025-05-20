/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -1e9 <= matrix[i][j] <= 1e9
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -1e9 <= target <= 1e9
*/

/*
Observations:

    Cell (0, 0): Assume we are starting traversal from (0, 0) and we are searching for 14. Now, this row and column are both sorted in increasing order. So, we cannot determine, how to move i.e. row-wise or column-wise. That is why, we cannot start traversal from (0, 0).

    Cell (0, m-1): Assume we are starting traversal from (0, m-1) and we are searching for 14. Now, in this case, the row is in decreasing order and the column is in increasing order. Therefore, if we start traversal from (0, m-1), in the following way, we can easily determine how we should move.
        If matrix[0][m-1] > target: We should move row-wise.
        If matrix[0][m-1] < target: We need bigger elements and so we should move column-wise.

    Cell (n-1, m-1): Assume we are starting traversal from (n-1, m-1) and we are searching for 14. Now, this row and column are both sorted in decreasing order. So, we cannot determine, how to move i.e. row-wise or column-wise. That is why, we cannot start traversal from (n-1, m-1).

    Cell (n-1, 0): Assume we are starting traversal from (n-1, 0) and we are searching for 14. Now, in this case, the row is in increasing order and the column is in decreasing order. Therefore, if we start traversal from (n-1, 0), in the following way,  we can easily determine how we should move.
        If matrix[n-1][0] < target: We should move row-wise.
        If matrix[n-1][0] > target: We need smaller elements and so we should move column-wise.
*/
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    // traverse the matrix from (0, m-1):
    while (row < n && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> q = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    if (searchMatrix(q, target))

        cout << "true" << endl;
    else
        cout << "false" << endl;
}