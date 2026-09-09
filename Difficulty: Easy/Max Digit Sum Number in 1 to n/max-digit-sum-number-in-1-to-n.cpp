class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int findMax(int n) {
        int ans = n;
        int bestSum = digitSum(n);
        int p = 1;

        while (p <= n) {
            int candidate = (n / (p * 10)) * (p * 10) + 
                            ((n / p) % 10 - 1) * p + (p - 1);

            if (candidate >= 1 && digitSum(candidate) >= bestSum) {
                if (digitSum(candidate) > bestSum ||
                    candidate > ans) {
                    bestSum = digitSum(candidate);
                    ans = candidate;
                }
            }

            p *= 10;
        }

        return ans;
    }
};