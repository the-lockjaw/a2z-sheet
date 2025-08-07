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
    // if answer is known, then return it
    if(dp[n][prev] != -1) return dp[n][prev];

    // base case
    if(n==0){
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != prev) maxi = max(maxi, points[0][i]);
        }
        return dp[n][prev] = maxi;
    }

    // solve one case
    int maxi = 0;
    for(int i = 0; i < 3; i++){
        if(i != prev) maxi = max(maxi, points[n][i] + memo_helper(points, dp , n-1, i));
    }

    // recursion
    return dp[n][prev] = maxi;
}

int ninja_training_memo(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return memo_helper(points, dp, n-1, 3);
}

int ninja_training_tab(vector<vector<int>> &points){
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // base case: day 0
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for(int i = 1; i < n; i++){
        for(int last = 0; last < 4; last++){
            dp[i][last] = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    dp[i][last] = max(dp[i][last], points[i][task] + dp[i-1][task]);
                }
            }
        }
    }

    return dp[n-1][3];
}

int ninja_training_so(int n, vector<vector<int>>& points) {
  vector<int> prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++)
        if (task != last)
          temp[last] = max(temp[last], points[day][task] + prev[task]);
    }
    prev = temp;
  }

  return prev[3];
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