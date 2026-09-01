class Solution {
  public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;

        long long perm = 1;
        long long ans = 0;

        int maxR = (n + 1) / 2;

        for (int r = 1; r <= maxR; r++) {
            perm = (perm * (k - r + 1)) % MOD;

            if (2 * r <= n) {
                // Both lengths 2r-1 and 2r exist
                ans = (ans + 2 * perm) % MOD;
            } else {
                // Only length 2r-1 exists
                ans = (ans + perm) % MOD;
            }
        }

        return ans;
    }
};