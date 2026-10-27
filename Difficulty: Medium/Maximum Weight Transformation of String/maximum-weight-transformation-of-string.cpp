
class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            // Keep current character separate
            dp[i] = dp[i - 1] + 1;

            // Pair the last two characters
            int cost = (s[i - 1] == s[i - 2]) ? 1 : 0;
            dp[i] = max(dp[i], dp[i - 2] + 4 - cost);
        }

        return dp[n];
    }
};
