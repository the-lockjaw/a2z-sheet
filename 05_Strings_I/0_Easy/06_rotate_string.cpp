/*
796. Rotate String
Easy
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
    For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false

Constraints:
    1 <= s.length, goal.length <= 100
    s and goal consist of lowercase English letters.
*/

// new trick learned . append the string with itself to figure out any possible rotated string.
// also read : Knuth-Morris-Pratt algorithm

#include <iostream>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s.substr(i, s.length() - i) + s.substr(0, i) == goal)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s = "abcde";
    string g = "abcde";
    if (rotateString(s, g))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}