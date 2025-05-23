/*
Given an integer numRows, return the first numRows of Pascal's triangle. In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
*/

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> v)
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

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    printMatrix(generate(n));
}