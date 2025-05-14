/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105
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
    cout << endl;
}

void print_vector(vector<int> v)
{
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {

        // remove duplicates:
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (!sum)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                // skip the duplicates:
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {1, 23, 23};
    print_matrix(threeSum(a));
}