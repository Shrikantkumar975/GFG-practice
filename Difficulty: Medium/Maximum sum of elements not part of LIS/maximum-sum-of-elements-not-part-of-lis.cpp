class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);           // LIS length ending at i
        vector<int> sumLis(n);          // LIS sum ending at i
        sumLis[0] = arr[0];

        for (int i = 1; i < n; ++i) {
            sumLis[i] = arr[i];
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        sumLis[i] = sumLis[j] + arr[i];
                    } else if (dp[j] + 1 == dp[i]) {
                        sumLis[i] = min(sumLis[i], sumLis[j] + arr[i]);
                    }
                }
            }
        }

        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int maxLen = *max_element(dp.begin(), dp.end());

        int minLisSum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLen) {
                minLisSum = min(minLisSum, sumLis[i]);
            }
        }

        return totalSum - minLisSum;
    }
};
