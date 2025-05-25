/*
8. String to Integer (atoi)
Medium
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
    Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
    Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.

Return the integer as the final result.

Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^

Example 2:
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^

Example 3:
Input: s = "1337c0d3"
Output: 1337
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^

Example 4:
Input: s = "0-1"
Output: 0
Explanation:
Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^

Example 5:
Input: s = "words and 987"
Output: 0
Explanation:
Reading stops at the first non-digit character 'w'.

Constraints:
    0 <= s.length <= 200
    s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/
#include <bits/stdc++.h>
using namespace std;

long long myStoi(string s)
{
    int left = 0;
    while (s[left]=='0')
    {
        left++;
    }
    
    long long ans = 0ll;
    long long multiplier = 1;
    for (int i = s.length() - 1; i >= left; i--)
    {
        ans += (s[i] - '0') * multiplier;
        multiplier *= 10;
    }
    return ans;
}

int myAtoi(string s)
{
    int left = 0, right;
    bool is_neg = false;
    while (s[left] == ' ')
    {
        left++;
    }
    if (s[left] == '+')
    {
        left++;
    }
    else if (s[left] == '-')
    {
        is_neg = true;
        left++;
    }
    if (s[left] < '0' || s[left] > '9')
    {
        return 0;
    }
    
    right = left;
    int j = left + 1;
    while (j < s.length())
    {
        if (s[j] >= '0' && s[j] <= '9')
        {
            right = j;
        }
        else
            break;
        j++;
    }
    long long ans = myStoi(s.substr(left, right - left + 1));
    if (is_neg)
        ans = -ans;
    if (ans > INT_MAX)
        return INT_MAX;
    else if (ans < INT_MIN)
        return INT_MIN;
    else
        return ans;
}

int main()
{
    string s = "  0000000000012345678";
    int ans = myAtoi(s);
    cout << "Answer = " << ans << endl;
}