#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return arr[i];
        if (j == i + 1) return max(arr[i], arr[j]);
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int pickLeft = arr[i] + min(solve(arr, i + 2, j, dp), solve(arr, i + 1, j - 1, dp));
        int pickRight = arr[j] + min(solve(arr, i + 1, j - 1, dp), solve(arr, i, j - 2, dp));
        
        return dp[i][j] = max(pickLeft, pickRight);
    }

    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 0, n - 1, dp);
    }
};
