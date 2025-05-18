/*
Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.
Example 1:
Input:
 arr = [4, 7, 1, 0]
Output:
 7 1 0
Explanation:
 Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]
Output:
 22 12 6
Explanation:
 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void print_vector(vector<int> v)
{
    for (auto a : v)
        cout << a << " ";
    cout << endl;
}

vector<int> leaders(vector<int> v)
{
    int max = INT_MIN;
    vector<int> ans;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] > max)
        {
            max = v[i];
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> q = {10, 22, 12, 3, 0, 6};
    print_vector(leaders(q));
}