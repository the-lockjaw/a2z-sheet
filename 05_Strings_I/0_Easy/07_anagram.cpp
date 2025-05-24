/*
242. Valid Anagram
Easy

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
    1 <= s.length, t.length <= 5 * 1e4
    s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    vector<int> count(26, 0);
    for (auto a : s)
    {
        count[a - 'a']++;
    }
    for (auto a : t)
    {
        count[a - 'a']--;
    }
    for (auto a : count)
    {
        if (a != 0)
            return false;
    }
    return true;
}

int main()
{
    string s = "car";
    string t = "rat";
    if (isAnagram(s, t))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}