class Solution {
  public:
    string compress(string &s) {
        int n = s.size();

        // KMP LPS array
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && s[i] != s[j])
                j = lps[j - 1];

            if (s[i] == s[j])
                j++;

            lps[i] = j;
        }

        string ans;

        int i = n - 1;

        while (i >= 0) {

            // A prefix of length i+1 can be compressed
            // only when its length is even.
            if (i % 2 == 1) {

                int len = i + 1;

                // Check whether the prefix is made by
                // repeating some smaller string.
                if (lps[i] >= len / 2 &&
                    len % (2 * (len - lps[i])) == 0) {

                    ans += '*';

                    // The '*' represents the second half,
                    // so move to the first half.
                    i = len / 2 - 1;

                    continue;
                }
            }

            ans += s[i];
            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};