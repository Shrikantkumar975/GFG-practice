
class Solution {
  public:
    int countBT(int h) {
        const long long MOD = 1000000007;

        if (h == 0) return 1;
        if (h == 1) return 1;

        long long prev2 = 1; // dp[0]
        long long prev1 = 1; // dp[1]

        for (int i = 2; i <= h; i++) {
            long long curr = (prev1 * prev1) % MOD;

            curr = (curr + 
                   (2LL * prev1 % MOD * prev2) % MOD) % MOD;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
