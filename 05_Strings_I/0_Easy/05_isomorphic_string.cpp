/*
205. Isomorphic Strings
Easy

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
    Mapping 'e' to 'a'.
    Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
    1 <= s.length <= 5 * 1e4
    t.length == s.length
    s and t consist of any valid ascii character.
*/
#include <iostream>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t)
{
    vector<int> indexS(200, 0); // Stores last seen index of character in string s
    vector<int> indexT(200, 0); // Stores last seen index of character in string t

    int len = s.length(); // Get the length of both strings

    if (len != t.length())
    { // If the lengths of the two strings are different, they can't be isomorphic
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        // s[i] and t[i] must have been last seen at the same index — otherwise the mapping is inconsistent.
        if (indexS[s[i]] != indexT[t[i]])
        {
            return false;
        }
        
        // We store i + 1 (not i) to distinguish from the default value 0 (which means "never seen").
        indexS[s[i]] = i + 1;
        indexT[t[i]] = i + 1;
    }

    return true;
}

int main()
{
    string s = "foo";
    string t = "bar";
    if (isIsomorphic(s, t))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}