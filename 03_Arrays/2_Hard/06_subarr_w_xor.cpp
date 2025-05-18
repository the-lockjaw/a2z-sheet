/*
Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

Example 1:
Input Format: A = [4, 2, 2, 6, 4] , k = 6
Result: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Example 2:
Input Format: A = [5, 6, 7, 8, 9], k = 5
Result: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subarrays_with_given_xor(vector<int> nums, int k)
{
    /*
    https://static.takeuforward.org/wp/uploads/2023/05/Screenshot-2023-05-02-011455.png
        if xr = xor of all elements till i,
        and there's a subarray of xor k from j to i
        let x = xor of all elements till j.
            => x ^ k = xr
            => x ^ k ^ k = xr ^ k
            => x = xr ^ k
        SO number of subarrays with xor = k till i = number of subarrays with sum xr ^ k
        THUS we are finding all subarrays ending with i

    Why do we need to set the value of 0 beforehand?
        Basically for null set {}, the xor is 0
        So if k = arr[0], then it will be counted as 1
    */
    map<int, int> mp;
    int ans = 0;
    int xr = 0;
    mp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        // xr = prefix xor of all elements till i
        xr = xr ^ nums[i];

        // x = xr ^ k
        int x = xr ^ k;

        // no of subarrays w/ xor = k ending at i = no of subarrays with prefix xor = x = xr ^ k
        ans += mp[x];

        // we found another prefix xor = xr
        mp[xr]++;
    }
    return ans;
}

int main()
{
    vector<int> v = {5, 6, 7, 8, 9};
    int k = 5;
    int ans = subarrays_with_given_xor(v, k);
    cout << "Answer = " << ans << endl;
}