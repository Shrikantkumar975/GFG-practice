
class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        int n = arr.size();

        int dp0 = arr[0];
        int dp1 = arr[0] * arr[0];

        int ans = max(dp0, dp1);

        for(int i = 1; i < n; i++) {
            int x = arr[i];

            int newDp1 = max({
                x * x,           // Start new subarray with square
                dp0 + x * x,     // Square current element
                dp1 + x          // Square was already used
            });

            int newDp0 = max(x, dp0 + x);

            dp0 = newDp0;
            dp1 = newDp1;

            ans = max({ans, dp0, dp1});
        }

        return ans;
    }
};
