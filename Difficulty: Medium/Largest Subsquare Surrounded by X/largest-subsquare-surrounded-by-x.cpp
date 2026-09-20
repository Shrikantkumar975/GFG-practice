class Solution {
public:
    int largestSubsquare(vector<vector<char>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        int maxi = 0;

        // first  = X's towards left
        // second = X's towards up
        vector<vector<pair<int,int>>> dp(
            n, vector<pair<int,int>>(m, {0,0})
        );

        // Build DP
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 'X') {

                    // Current cell itself
                    dp[i][j].first = 1;
                    dp[i][j].second = 1;

                    // Left
                    if(j > 0 && mat[i][j-1] == 'X') {
                        dp[i][j].first += dp[i][j-1].first;
                    }

                    // Up
                    if(i > 0 && mat[i-1][j] == 'X') {
                        dp[i][j].second += dp[i-1][j].second;
                    }
                }
            }
        }

        // Check every cell as bottom-right corner
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] != 'X')
                    continue;

                // Bottom and right borders are already known
                int len = min(dp[i][j].first,
                              dp[i][j].second);

                while(len > maxi) {

                    int top = i - len + 1;
                    int left = j - len + 1;

                    if(top >= 0 && left >= 0) {

                        // Top border
                        bool topBorder =
                            dp[top][j].first >= len;

                        // Left border
                        bool leftBorder =
                            dp[i][left].second >= len;

                        if(topBorder && leftBorder) {
                            maxi = len;
                            break;
                        }
                    }

                    len--;
                }
            }
        }

        return maxi;
    }
};