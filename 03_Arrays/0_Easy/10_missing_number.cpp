#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ideal_sum = (n * (n + 1)) / 2;
    int sum = 0;
    for (auto a : nums)
        sum += a;
    return ideal_sum - sum;
}