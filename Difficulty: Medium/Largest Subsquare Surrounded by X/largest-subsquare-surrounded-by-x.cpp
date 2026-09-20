class Solution {
public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // first  = consecutive X's towards left
        // second = consecutive X's towards up
        vector<vector<pair<int, int>>> dp(
            n, vector<pair<int, int>>(m, {0, 0})
        );

        // Build left and up counts
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 'X') {

                    // Left
                    dp[i][j].first = 1;
                    if (j > 0)
                        dp[i][j].first += dp[i][j - 1].first;

                    // Up
                    dp[i][j].second = 1;
                    if (i > 0)
                        dp[i][j].second += dp[i - 1][j].second;
                }
            }
        }

        int ans = 0;

        // Treat (i,j) as bottom-right corner
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                // Possible side length cannot exceed
                // number of X's going left or up
                int len = min(dp[i][j].first, dp[i][j].second);

                while (len > ans) {

                    int topRow = i - len + 1;
                    int leftCol = j - len + 1;

                    if (topRow >= 0 && leftCol >= 0) {

                        // Top border
                        int topX = dp[topRow][j].first;

                        // Left border
                        int leftX = dp[i][leftCol].second;

                        if (topX >= len && leftX >= len) {
                            ans = len;
                            break;
                        }
                    }

                    len--;
                }
            }
        }

        return ans;
    }
};