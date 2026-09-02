class Solution {
  public:
    int solve(int n, string s) {
        set<char> used;
        set<char> rejected;

        int ans = 0;

        for (char c : s) {
            // Customer arrives
            if (used.find(c) == used.end() &&
                rejected.find(c) == rejected.end()) {

                if (used.size() < n) {
                    used.insert(c);
                } else {
                    rejected.insert(c);
                    ans++;
                }
            }
            // Customer leaves
            else if (used.find(c) != used.end()) {
                used.erase(c);
            }
        }

        return ans;
    }
};