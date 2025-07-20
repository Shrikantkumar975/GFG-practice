class Solution {
public:
    static int fastPow(int base, int exp) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= base;
            }
            base *= base;
            exp /= 2;
        }
        return result;
    }

    static int countValid(int n, vector<int>& arr) {
        vector<bool> good(10, false);
        for (int d : arr) {
            good[d] = true;
        }

        int c = 0, nonzero = 0;
        for (int d = 0; d < 10; d++) {
            if (!good[d]) {
                c++;
                if (d != 0) nonzero++;
            }
        }

        int total = 9 * fastPow(10, n - 1);
        int noneAllowed = (n == 1) ? nonzero : nonzero * fastPow(c, n - 1);
        return total - noneAllowed;
    }
};