class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int sum = 0;
        for (int x : arr) sum += x;

        // Edge cases
        if ((target + sum) % 2 != 0 || abs(target) > sum)
            return 0;

        int s = (target + sum) / 2;

        vector<int> dp(s + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int j = s; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[s];
    }
};