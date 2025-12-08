class Solution {
public:
    string solve(int i, int j, vector<vector<int>>& split) {
        if (i == j) {
            // Convert matrix index to letter A,B,C,...
            char c = 'A' + (i - 1);
            return string(1, c);
        }
        int k = split[i][j];
        string left = solve(i, k, split);
        string right = solve(k + 1, j, split);
        return "(" + left + right + ")";
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();      // n dimensions => n-1 matrices
        int m = n - 1;

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        vector<vector<int>> split(m + 1, vector<int>(m + 1, 0));

        // gap DP: l = chain length
        for (int len = 2; len <= m; len++) {
            for (int i = 1; i + len - 1 <= m; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j]
                                     + 1LL * arr[i-1] * arr[k] * arr[j];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        return solve(1, m, split);
    }
};
