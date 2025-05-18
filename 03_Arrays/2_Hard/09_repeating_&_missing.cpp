/*
You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Example 1:
Input Format:  array[] = {3,1,2,5,3}
Result: {3,4)
Explanation: A = 3 , B = 4
Since 3 is appearing twice and 4 is missing

Example 2:
Input Format: array[] = {3,1,2,5,4,6,7,5}
Result: {5,8)
Explanation: A = 5 , B = 8
Since 5 is appearing twice and 8 is missing
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> repeating_and_missing(vector<int> &a)
{
    int n = a.size(); // size of the array

    int xr = 0;

    // Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }
    // xr = X ^ Y = repeating ^ missing

    // Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));
    // bit manipulation

    // Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        // part of 1 group:
        if ((a[i] & number) != 0)
        {
            one = one ^ a[i];
        }
        // part of 0 group:
        else
        {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // part of 1 group:
        if ((i & number) != 0)
        {
            one = one ^ i;
        }
        // part of 0 group:
        else
        {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
            cnt++;
    }

    if (cnt == 2)
        return {zero, one};
    return {one, zero};
}

int main()
{
    vector<int> q = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = repeating_and_missing(q);
    cout << "Repeating = " << ans[0] << endl;
    cout << "Missing = " << ans[1] << endl;
}