/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]


Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> v)
{
    for (auto a : v)
    {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

void setZeroes(vector<vector<int>> &matrix)
{
    unordered_set<int> x;
    unordered_set<int> y;
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            if (!matrix[i][j])
            {
                x.insert(i);
                y.insert(j);
            }

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            if ((x.find(i) != x.end()) || (y.find(j) != y.end()))
            {
                matrix[i][j] = 0;
            }
}

int main()
{
    vector<vector<int>> q = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    cout << "Original Matrix = " << endl;
    print_matrix(q);

    setZeroes(q);

    cout << "Modified Matrix = " << endl;
    print_matrix(q);
}