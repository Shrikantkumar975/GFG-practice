class Solution {
  public:
    long long ncr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);   // optimization
        
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }
    
    long long findWays(int n) {
        // n = length
        if (n % 2 != 0) return 0;
        
        int pairs = n / 2;
        return ncr(2 * pairs, pairs) / (pairs + 1);
    }
};
