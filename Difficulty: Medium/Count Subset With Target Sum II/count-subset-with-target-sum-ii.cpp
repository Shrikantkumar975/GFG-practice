class Solution {
public:
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        unordered_map<int, int> mp1, mp2;

        // subset sums for left
        int n1 = left.size();
        for (int mask = 0; mask < (1 << n1); mask++) {
            int sum = 0;
            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i))
                    sum += left[i];
            }
            mp1[sum]++;
        }

        // subset sums for right
        int n2 = right.size();
        for (int mask = 0; mask < (1 << n2); mask++) {
            int sum = 0;
            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i))
                    sum += right[i];
            }
            mp2[sum]++;
        }

        int ans = 0;
        for (auto &p : mp1) {
            int sumL = p.first;
            int cntL = p.second;
            int need = k - sumL;

            if (mp2.count(need))
                ans += cntL * mp2[need];
        }

        return ans;
    }
};
