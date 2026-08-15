#include <string>
#include <cmath>

class Solution {
  public:
    int countWithout(int n, int d) {
        if (n == 0) return 0;

        std::string s = std::to_string(n);
        int len = s.length();

        // 1. Precalculate powers of 9
        // pow9[i] represents how many valid numbers can be formed using i digits 
        // choosing from 9 available choices (0 to 9 except 'd')
        int pow9[11];
        pow9[0] = 1;
        for (int i = 1; i <= 10; i++) {
            pow9[i] = pow9[i - 1] * 9;
        }

        // 2. Count all valid numbers strictly shorter than len digits
        // For length i, the first digit has 8 choices (1-9 excluding d), 
        // and the remaining (i-1) digits have 9 choices each.
        int total = 0;
        for (int i = 1; i < len; i++) {
            if (d == 0) {
                total += 9 * pow9[i - 1]; // All digits 1-9 are available for the first place
            } else {
                total += 8 * pow9[i - 1]; // Digits 1-9 except d are available for the first place
            }
        }

        // 3. Count valid numbers of exact length 'len' up to n
        bool prefix_valid = true;
        for (int i = 0; i < len; i++) {
            int current_digit = s[i] - '0';

            // Count options lower than the current digit at this position
            int start_digit = (i == 0) ? 1 : 0; 
            for (int digit = start_digit; digit < current_digit; digit++) {
                if (digit != d) {
                    total += pow9[len - 1 - i];
                }
            }

            // If the current prefix digit matches the forbidden digit d, 
            // no numbers matching this prefix further down can be valid. Break out.
            if (current_digit == d) {
                prefix_valid = false;
                break;
            }
        }

        // If the number n itself is valid, add it to the count
        if (prefix_valid) {
            total += 1;
        }

        return total;
    }
};
