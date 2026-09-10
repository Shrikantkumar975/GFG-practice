class Solution {
  public:
    int pairCount(int x, int y) {
        if (y % x != 0)
            return 0;

        int n = y / x;
        int ans = 0;

        for (int a = 1; a <= n; a++) {
            if (n % a == 0) {
                int b = n / a;

                if (__gcd(a, b) == 1)
                    ans++;
            }
        }

        return ans;
    }
};