/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

Constraints:
    1 <= piles.length <= 1e4
    piles.length <= h <= 1e9
    1 <= piles[i] <= 1e9
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int find_max_pile(vector<int> &piles)
{
    int max = INT_MIN;
    for (auto a : piles)
        if (a > max)
            max = a;
    return max;
}

bool can_finish(vector<int> &piles, int h, int k)
{
    int hours_req = 0;
    for (auto a : piles)
    {
        // as you are adding here keep in mind integer oveflow
        hours_req += a / k;
        if (a % k)
        {
            ++hours_req;
        }
        if (hours_req>h)
        {
            return false;
        }
        
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    // left != 0, division by zero not possible and she at least needs to eat one banana per hour to finish all
    int left = 1;
    int right = find_max_pile(piles);
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (can_finish(piles, h, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> piles = {805306368, 805306368, 805306368};
    int h = 1000000000;
    int k = minEatingSpeed(piles, h);
    cout << "Minimum eating speed = " << k << endl;
}