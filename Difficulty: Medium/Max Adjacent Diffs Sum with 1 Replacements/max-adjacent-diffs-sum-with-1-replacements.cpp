class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1)
            return 0;

        long long dp0 = 0;
        long long dp1 = 0;

        for (int i = 1; i < n; i++) {

            long long new_dp0 = max(
                dp0 + abs(arr[i] - arr[i - 1]),
                dp1 + abs(arr[i] - 1)
            );

            long long new_dp1 = max(
                dp0 + abs(1 - arr[i - 1]),
                dp1
            );

            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        return (int)max(dp0, dp1);
    }
};