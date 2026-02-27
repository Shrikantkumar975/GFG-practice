class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {

        int n = mat.size();
        int m = mat[0].size();

        // Step 1: build prefix sum
        vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                    + prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1];
            }
        }

        int count = 0;

        // Step 2: try all square sizes
        for (int len = 1; len <= min(n, m); len++) {

            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= m; j++) {

                    int r1 = i;
                    int c1 = j;
                    int r2 = i + len;
                    int c2 = j + len;

                    long long sum =
                        prefix[r2][c2]
                        - prefix[r1][c2]
                        - prefix[r2][c1]
                        + prefix[r1][c1];

                    if (sum == x)
                        count++;
                }
            }
        }

        return count;
    }
};