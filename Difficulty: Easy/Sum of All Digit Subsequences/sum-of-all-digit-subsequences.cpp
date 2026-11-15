
class Solution {
public:
    int subsequenceSum(string &s) {
        long long sum = 0;
        int n = s.size();

        const long long mod = 1000000007;

        for (char c : s) {
            sum = (sum + (c - '0')) % mod;
        }

        long long num = 1;

        for (int i = 0; i < n - 1; i++) {
            num = (num * 2) % mod;
        }

        return (sum * num) % mod;
    }
};
