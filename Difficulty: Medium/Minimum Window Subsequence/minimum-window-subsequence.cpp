class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        int i = 0;
        while (i < n) {
            // Step 1: Forward match s2
            int j = 0;
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m)
                        break;
                }
                i++;
            }

            if (j != m) break;  // No more subsequences

            // Step 2: Backward minimize window
            int end = i;
            j = m - 1;
            while (i >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                    if (j < 0)
                        break;
                }
                i--;
            }
            i++; // adjust start position

            // Step 3: Update answer
            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                start = i;
            }

            i++; // move forward to find next window
        }

        return start == -1 ? "" : s1.substr(start-1, minLen+1);
    }
};
