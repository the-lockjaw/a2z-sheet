/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

Constraints:
    1 <= nums.length <= 5 * 104
    -109 <= nums[i] <= 109

Follow up: Could you solve the problem in linear time and in O(1) space?
*/
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> a)
{
    cout << "printing answer: " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> majorityElement(vector<int> &nums)
{
    // there can be two majority elements as count > ⌊n/3⌋ can only be for 2 elements
    int maj_1 = -1;
    int maj_2 = -1;

    // initialise count for both
    int count_1 = 0;
    int count_2 = 0;

    for (auto a : nums)
    {
        // IMP! check if the majority elements do not match with the other before assignment
        if (count_1 == 0 && a != maj_2)
        {
            maj_1 = a;
            count_1 = 1;
        }
        else if (count_2 == 0 && a != maj_1)
        {
            maj_2 = a;
            count_2 = 1;
        }
        else if (a == maj_1)
        {
            count_1++;
        }
        else if (a == maj_2)
        {
            count_2++;
        }
        else
        {
            count_1--;
            count_2--;
        }
    }
    vector<int> ans;
    count_1 = count_2 = 0;
    for (auto a : nums)
    {
        if (a == maj_1)
        {
            count_1++;
        }
        else if (a == maj_2)
        {
            count_2++;
        }
    }

    if (count_1 > nums.size() / 3)
    {
        ans.push_back(maj_1);
    }
    if (count_2 > nums.size() / 3)
    {
        ans.push_back(maj_2);
    }
    return ans;
}

int main()
{
    vector<int> q = {};
    vector<int> ans = majorityElement(q);
    cout << "Answer = ";
    print_vector(ans);
}