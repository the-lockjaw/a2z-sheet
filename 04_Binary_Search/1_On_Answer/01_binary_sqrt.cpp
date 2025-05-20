/*
You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.
*/
#include <iostream>
using namespace std;

int binary_sqrt(int x)
{
    int left = 1;
    int right = x;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int x = 4;
    int ans = binary_sqrt(x);
    cout << "Square root of " << x << " is " << ans << endl;
}