class Solution {
  public:
    int optimalKeys(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // press A
            dp[i] = dp[i - 1] + 1;
            
            // try copy-paste operations
            for (int j = 3; j < i; j++) {
                dp[i] = max(dp[i], dp[i - j] * (j - 1));
            }
        }
        
        return dp[n];
    }
};