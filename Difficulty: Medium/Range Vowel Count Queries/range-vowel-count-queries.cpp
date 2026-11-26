
class Solution {
public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {

        int n = s.size();
        vector<int> prefix(n, 0);

        for (int i = 0; i < n; i++) {
            int isVowel = (s[i] == 'a' || s[i] == 'e' ||
                           s[i] == 'i' || s[i] == 'o' ||
                           s[i] == 'u');

            prefix[i] = isVowel;

            if (i > 0) {
                prefix[i] += prefix[i - 1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int count = prefix[r];

            if (l > 0) {
                count -= prefix[l - 1];
            }

            ans.push_back(count);
        }

        return ans;
    }
};
