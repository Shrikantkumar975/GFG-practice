class Solution {
public:
    int countConsec(int n) {
        if (n == 2) {                // Base: only "11" has consecutive 1’s when length = 2
            return 1;
        }

        int firstNum  = 0;          // Fib(i-2)
        int secondNum = 1;          // Fib(i-1)
        int thirdNum;               // Fib(i)
        int result = 1;             // Count of “bad” strings for length = 2

        for (int i = 3; i <= n; ++i) {
            thirdNum  = firstNum + secondNum;     // Compute Fib(i)
            result    = result * 2 + thirdNum;    // Double previous + new “11” endings
            firstNum  = secondNum;                // Shift window
            secondNum = thirdNum;
        }

        return result;               // Final count for length = n
    }
};