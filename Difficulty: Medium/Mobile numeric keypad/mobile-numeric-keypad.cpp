class Solution {
public:

    int dp[4][3][16];

    int solve(int i, int j, int n) {
        // invalid or forbidden cells (* and #)
        if (i < 0 || i >= 4 || j < 0 || j >= 3 ||
            (i == 3 && (j == 0 || j == 2))) {
            return 0;
        }

        // base case: sequence length 1 → only the current key
        if (n == 1) {
            return 1;
        }

        // return cached result if available
        if (dp[i][j][n] != -1) {
            return dp[i][j][n];
        }

        int result = 0;
        // stay in place
        result += solve(i, j, n - 1) +
                  // move up
                  solve(i - 1, j, n - 1) +
                  // move left
                  solve(i, j - 1, n - 1) +
                  // move right
                  solve(i, j + 1, n - 1) +
                  // move down
                  solve(i + 1, j, n - 1);

        // cache and return
        return dp[i][j][n] = result;
    }

    int getCount(int n) {
        int count = 0;

        // initialize memo table
        memset(dp, -1, sizeof(dp));
        // iterate over all starting cells
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                count += solve(i, j, n);
            }
        }
        return count;
    }
};
