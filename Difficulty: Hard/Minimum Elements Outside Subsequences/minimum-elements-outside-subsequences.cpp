class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        // dp[inc][dec] = maximum elements selected
        // inc = last element of increasing subsequence
        // dec = last element of decreasing subsequence
        vector<vector<int>> dp(102, vector<int>(102, -1));

        dp[0][101] = 0;

        for (int x : arr) {
            vector<vector<int>> ndp = dp;

            for (int inc = 0; inc <= 100; inc++) {
                for (int dec = 1; dec <= 101; dec++) {
                    if (dp[inc][dec] == -1)
                        continue;

                    // Put x in increasing subsequence
                    if (x > inc) {
                        ndp[x][dec] = max(ndp[x][dec],
                                          dp[inc][dec] + 1);
                    }

                    // Put x in decreasing subsequence
                    if (x < dec) {
                        ndp[inc][x] = max(ndp[inc][x],
                                          dp[inc][dec] + 1);
                    }

                    // Skip x
                    // Already handled by ndp = dp
                }
            }

            dp = ndp;
        }

        int maximumSelected = 0;

        for (int inc = 0; inc <= 100; inc++) {
            for (int dec = 1; dec <= 101; dec++) {
                maximumSelected = max(maximumSelected, dp[inc][dec]);
            }
        }

        return n - maximumSelected;
    }
};