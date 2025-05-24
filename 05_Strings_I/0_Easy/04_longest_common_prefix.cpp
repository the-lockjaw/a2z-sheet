/*
14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.



Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.
*/
#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    // edge case
    if (strs.empty())
        return "";

    for (int i = 0; i < strs[0].size(); i++)
    {
        // only check all characters of first string
        char c = strs[0][i];

        // check upto which index all characters are common
        for (int j = 1; j < strs.size(); j++)
        {
            if (i == strs[j].size() || strs[j][i] != c)
                return strs[0].substr(0, i);
        }
    }
    return strs[0];
}

int main()
{
    vector<string> v = {"flower", "flow", "flight"};
    string ans = longestCommonPrefix(v);
    cout << "Longest common prefix = " << ans << endl;
}
