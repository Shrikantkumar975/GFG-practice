class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {

        int n = arr.size();

        vector<int> bestEnd(n);

        bestEnd[0] = arr[0];

        for (int i = 1; i < n; i++) {
            bestEnd[i] = max(arr[i], bestEnd[i - 1] + arr[i]);
        }

        int windowSum = 0;

        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        int ans = windowSum;

        for (int end = k - 1; end < n; end++) {

            int start = end - k + 1;

            ans = max(ans, windowSum);

            if (start > 0)
                ans = max(ans, windowSum + bestEnd[start - 1]);

            if (end + 1 < n) {
                windowSum += arr[end + 1];
                windowSum -= arr[start];
            }
        }

        return ans;
    }
};