/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_matrix(vector<vector<int>> v)
{
    for (auto a : v)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    { // remove duplicates:
        if (i != 0 && nums[i] == nums[i - 1])
            continue;
        for (int l = i + 1; l < nums.size(); l++)
        {

            // remove duplicates:
            if (l > i + 1 && nums[l] == nums[l - 1])
                continue;

            int j = l + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[l], nums[j], nums[k]});
                    j++;
                    k--;

                    // skip the duplicates:
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> q = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum(q, target);
    print_matrix(ans);
}