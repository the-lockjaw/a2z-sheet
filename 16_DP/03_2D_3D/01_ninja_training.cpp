/*
A ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn.
*/

#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>> &v)
{
    for (auto a : v)
    {
        for (auto b : a)
            cout << b << " ";
        cout << "\n";
    }
    cout << "\n";
}

// prev tracks the previous chosen index, if it is == 3 then this is the first element we are picking
int memo_helper(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int prev){
    // if answer is none, then return it
    if(dp[n][prev] != -1) return dp[n][prev];

    if(n==0){
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != prev) maxi = max(maxi, points[0][i]);
        }
        return dp[n][prev] = maxi;
    }

    int maxi = 0;
    for(int i = 0; i < 3; i++){
        if(i != prev) maxi = max(maxi, points[n][i] + memo_helper(points, dp , n-1, i));
    }
    return dp[n][prev] = maxi;
}

int ninja_training_memo(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    cout<<"DP Table : \n";
    int ans = memo_helper(points, dp, n-1, 3);
    print_matrix(dp);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> points[i][j];
    // print_matrix(points);
    int ans_memo = ninja_training_memo(points);
    cout << "Memoization Answer : " << ans_memo << "\n";
}