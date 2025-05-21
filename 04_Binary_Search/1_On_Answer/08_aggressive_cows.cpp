/*
You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.

Example 1:
Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result: 3
Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format: N = 5, k = 2, arr[] = {4,2,1,3,6}
Result: 5
Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}.
*/
#include <bits/stdc++.h>
using namespace std;

int find_min_dist(vector<int> &stalls)
{
    if (stalls.size() <= 1)
        return -1;
    int distance = INT_MAX;
    for (int i = 1; i < stalls.size(); i++)
    {
        distance = min(distance, stalls[i] - stalls[i - 1]);
    }
    return distance;
}

bool check(vector<int> &stalls, int k, int x)
{
    int last_placed_cow = stalls[0];
    int cows_placed = 1;
    for (int i = 1; i < stalls.size(); i++)
    {
        // this should be >= as if the distance is equal to min distance, we must place a cow here, not at the next stall
        if (stalls[i] - last_placed_cow >= x)
        {
            cows_placed++;
            last_placed_cow = stalls[i];
        }
    }
    return cows_placed >= k;
}

int aggressive_cows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int left = find_min_dist(stalls);
    int right = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(stalls, k, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressive_cows(stalls, k);
    cout << "answer = " << ans << endl;
}