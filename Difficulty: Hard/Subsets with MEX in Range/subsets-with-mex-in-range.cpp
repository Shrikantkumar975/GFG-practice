
class Solution {
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return ans;
    }

    long long countAtLeast(int k, vector<int>& freq,
                           vector<int>& suffix,
                           vector<long long>& pow2) {

        long long ans = 1;

        // Every number from 0 to k-1 must be present
        for (int i = 0; i < k; i++) {
            if (freq[i] == 0) {
                return 0;
            }

            ans = (ans * (pow2[freq[i]] - 1 + MOD)) % MOD;
        }

        // Elements >= k can be selected freely
        ans = (ans * pow2[suffix[k]]) % MOD;

        return ans;
    }

public:
    int cntSubsets(vector<int>& arr, int l, int r) {
        int n = arr.size();

        vector<int> freq(n + 1, 0);

        for (int x : arr) {
            freq[x]++;
        }

        // Precompute powers of 2
        vector<long long> pow2(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        // suffix[i] = number of elements >= i
        vector<int> suffix(n + 2, 0);

        for (int i = n; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + freq[i];
        }

        long long a = countAtLeast(l, freq, suffix, pow2);
        long long b = countAtLeast(r + 1, freq, suffix, pow2);

        return (a - b + MOD) % MOD;
    }
};
