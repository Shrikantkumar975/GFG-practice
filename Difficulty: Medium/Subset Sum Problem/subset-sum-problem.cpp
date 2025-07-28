class Solution {
  public:
    bool fun(vector<int>& arr, int start, int sum, vector<vector<int>> &dp) {
        if (sum == 0) return true;
        if (start == arr.size()) return false;
        if (dp[start][sum] != -1) return dp[start][sum];

        // Include arr[start] if it's not more than remaining sum
        if (arr[start] <= sum) {
            if (fun(arr, start + 1, sum - arr[start], dp)) {
                return dp[start][sum] = true;
            }
        }

        // Exclude arr[start]
        return dp[start][sum] = fun(arr, start + 1, sum, dp);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));  // -1 = uncomputed
        return fun(arr, 0, sum, dp);
    }
};
