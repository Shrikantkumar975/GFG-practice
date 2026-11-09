
class Solution {
public:
    int getCount(string &s, int k) {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            // A new group starts
            if (i == 0 || s[i] != s[i - 1]) {
                freq[s[i] - 'a']++;
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == k) {
                ans++;
            }
        }

        return ans;
    }
};
