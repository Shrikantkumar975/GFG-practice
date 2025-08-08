class Solution {
  public:
    int getLPSLength(string &s) {
    
    int base1 = 31, base2 = 37;
    int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

    int p1 = 1, p2 = 1;
    int n = s.size();

    // hash1 for prefix, hash2 for suffix
    vector<int> hash1(2, 0), hash2(2, 0);
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {

        // Update prefix hashes
        hash1[0] = (hash1[0] + 1LL * 
                    (s[i] - 'a' + 1) * p1 % mod1) % mod1;
        hash1[1] = (hash1[1] + 1LL * 
                    (s[i] - 'a' + 1) * p2 % mod2) % mod2;

        // Update suffix hashes
        hash2[0] = (1LL * hash2[0] * base1 % mod1 + 
                        (s[n - i - 1] - 'a' + 1)) % mod1;
        hash2[1] = (1LL * hash2[1] * base2 % mod2 + 
                        (s[n - i - 1] - 'a' + 1)) % mod2;

        // Check if both hash pairs match
        if (hash1 == hash2) {
            ans = i + 1;
        }

        // Update powers
        p1 = 1LL * p1 * base1 % mod1;
        p2 = 1LL * p2 * base2 % mod2;
    }

    return ans;
}
};