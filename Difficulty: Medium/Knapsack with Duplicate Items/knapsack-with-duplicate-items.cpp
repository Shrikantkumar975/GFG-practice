// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];  // Can't include this item
                else
                    dp[i][j] = max(
                        dp[i - 1][j],                             // Exclude item
                        val[i - 1] + dp[i][j - wt[i - 1]]     // Include item
                    );
            }
        }
        return dp[n][W];
    }
};