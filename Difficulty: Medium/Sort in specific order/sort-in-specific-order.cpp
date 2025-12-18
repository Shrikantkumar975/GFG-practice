

class Solution {
  public:
    void sortIt(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [](int a, int b) {
            bool a_is_odd = (a % 2 != 0);
            bool b_is_odd = (b % 2 != 0);

            // Case 1: One is odd and the other is even
            if (a_is_odd && !b_is_odd) {
                return true; // Odd comes before even
            }
            if (!a_is_odd && b_is_odd) {
                return false; // Even comes after odd
            }

            // Case 2: Both are odd
            if (a_is_odd && b_is_odd) {
                return a > b; // Descending order
            }

            // Case 3: Both are even
            return a < b; // Ascending order
        });
    }
};
