/*
547. Number of Provinces
Medium

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:
    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]
*/

#include <iostream>
#include <vector>
using namespace std;

int findCircleNum(vector<vector<int>> &isConnected)
{
    int provinces = 1;
    for (int i = 1; i < isConnected.size(); i++)
    {
        bool is_connected = false;
        for (int j = 0; j < i; j++)
        {
            if (isConnected[i][j])
                is_connected = true;
        }
        if (!is_connected)
            provinces++;
    }
    return provinces;
}

int main()
{
    vector<vector<int>> q = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> r = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int ans = findCircleNum(r);
    cout << ans << endl;
}