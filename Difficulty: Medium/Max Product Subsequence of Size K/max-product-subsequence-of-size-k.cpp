class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();

        vector<vector<long long>> mx(k + 1,
            vector<long long>(n + 1, LLONG_MIN));

        vector<vector<long long>> mn(k + 1,
            vector<long long>(n + 1, LLONG_MAX));

        mx[0][0] = 1;
        mn[0][0] = 1;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= min(i, k); j++) {

                // Don't take arr[i-1]
                if (i > j) {
                    mx[j][i] = mx[j][i - 1];
                    mn[j][i] = mn[j][i - 1];
                }

                // Take arr[i-1]
                if (j > 0) {

                    long long x = arr[i - 1];

                    if (mx[j - 1][i - 1] != LLONG_MIN) {
                        long long val =
                            mx[j - 1][i - 1] * x;

                        mx[j][i] = max(mx[j][i], val);
                        mn[j][i] = min(mn[j][i], val);
                    }

                    if (mn[j - 1][i - 1] != LLONG_MAX) {
                        long long val =
                            mn[j - 1][i - 1] * x;

                        mx[j][i] = max(mx[j][i], val);
                        mn[j][i] = min(mn[j][i], val);
                    }
                }
            }
        }

        return mx[k][n];
    }
};