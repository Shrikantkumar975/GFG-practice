class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const long long MOD = 1e9 + 7;

        vector<vector<vector<long long>>> ans(
            m, vector<vector<long long>>(n, {0, 0})
        );

        ans[0][0][0] = 1;
        ans[0][0][1] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == m - 1 && j == n - 1)
                    continue;
                    
                // No path reaches this cell
                if (ans[i][j][0] == 0)
                    continue;

                if (grid[i][j] == 1) {

                    // Right only
                    if (j + 1 < n) {
                        ans[i][j + 1][0] =
                            (ans[i][j + 1][0] + ans[i][j][0]) % MOD;

                        ans[i][j + 1][1] =
                            max(ans[i][j + 1][1],
                                ans[i][j][1] + grid[i][j + 1]);
                    }

                } else if (grid[i][j] == 2) {

                    // Down only
                    if (i + 1 < m) {
                        ans[i + 1][j][0] =
                            (ans[i + 1][j][0] + ans[i][j][0]) % MOD;

                        ans[i + 1][j][1] =
                            max(ans[i + 1][j][1],
                                ans[i][j][1] + grid[i + 1][j]);
                    }

                } else {

                    // Right
                    if (j + 1 < n) {
                        ans[i][j + 1][0] =
                            (ans[i][j + 1][0] + ans[i][j][0]) % MOD;

                        ans[i][j + 1][1] =
                            max(ans[i][j + 1][1],
                                ans[i][j][1] + grid[i][j + 1]);
                    }

                    // Down
                    if (i + 1 < m) {
                        ans[i + 1][j][0] =
                            (ans[i + 1][j][0] + ans[i][j][0]) % MOD;

                        ans[i + 1][j][1] =
                            max(ans[i + 1][j][1],
                                ans[i][j][1] + grid[i + 1][j]);
                    }
                }
            }
        }

        return {
            (int)ans[m - 1][n - 1][0],
            (int)ans[m - 1][n - 1][1]
        };
    }
};