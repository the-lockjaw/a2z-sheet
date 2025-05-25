/*
5. Longest Palindromic Substring
Medium

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    string ans = s.substr(0, 1);
    for (int i = 0; i < s.length(); i++)
    {
        // odd length palindrome
        int left = i, right = i;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            if (right - left + 1 > ans.length())
                ans = s.substr(left, right - left + 1);
            left--;
            right++;
        }

        // even length palindrome
        left = i;
        right = i + 1;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            if (right - left + 1 > ans.length())
                ans = s.substr(left, right - left + 1);
            left--;
            right++;
        }
    }

    return ans;
}

int main()
{
    string s = "cbbd";
    string ans = longestPalindrome(s);
    cout << "answer = " << ans << endl;
}