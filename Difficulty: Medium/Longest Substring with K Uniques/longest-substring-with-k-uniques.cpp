class Solution {
public:
    int longestKSubstr(string& s, int k) {
        int n = s.length();
        unordered_map<char, int> mp; // map to store frequency of chars in current window

        int i = 0;                   // left pointer of window
        int j = 0;                   // right pointer of window

        int result = -1;             // store max length found

        while (j < n) {
            mp[s[j]]++;   // include s[j] in window

            // if more than k distinct, shrink from left
            if (mp.size() > k) {
                mp[s[i]]--;          // decrement freq of s[i]
                if (mp[s[i]] == 0) { // if freq becomes 0, remove from map
                    mp.erase(s[i]);
                }
                i++;               // move left pointer
            }

            // if exactly k distinct, update result
            if (mp.size() == k) {
                result = max(result, j - i + 1);
            }
            j++;  // expand right pointer
        }
        return result;
    }
};