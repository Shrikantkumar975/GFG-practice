class Solution {
public:
    int minCost(int n, int i, int d, int c) {
        if (n == 0) return 0;

        vector<long long> dp(n + 1, 0);

        // dp[x] + 2*x*d
        deque<int> dq;

        dp[0] = 0;

        for (int x = 1; x <= n; x++) {

            // k must satisfy:
            // ceil(x/2) <= k < x
            int k = x - 1;

            long long value = dp[k] + 2LL * k * d;

            // Insert k while maintaining increasing values
            while (!dq.empty()) {
                int back = dq.back();

                long long backValue =
                    dp[back] + 2LL * back * d;

                if (backValue <= value)
                    break;

                dq.pop_back();
            }

            dq.push_back(k);

            // Remove k < ceil(x/2)
            int low = (x + 1) / 2;

            while (!dq.empty() && dq.front() < low)
                dq.pop_front();

            // Option 1: Insert one character
            dp[x] = dp[x - 1] + i;

            // Option 2: Copy and then delete
            if (!dq.empty()) {
                int best = dq.front();

                long long copyDelete =
                    dp[best]
                    + c
                    + (2LL * best - x) * d;

                dp[x] = min(dp[x], copyDelete);
            }
        }

        return dp[n];
    }
};