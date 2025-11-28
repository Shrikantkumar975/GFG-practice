class Solution {
  public:
    vector<int> subsetXOR(int n) {
    vector<int> ans;
    int r = n % 4;

    // n % 4 = 0 → XOR already n
    if (r == 0) {
        for (int i = 1; i <= n; i++) ans.push_back(i);
    }
    // n % 4 = 2 → XOR = n+1 → remove 1
    else if (r == 2) {
        for (int i = 2; i <= n; i++) ans.push_back(i);
    }
    // n % 4 = 3 → XOR = 0 → remove n
    else if (r == 3) {
        for (int i = 1; i < n; i++) ans.push_back(i);
    }
    // n % 4 = 1 → XOR = 1 → remove n-1
    else {
        for (int i = 1; i <= n; i++) {
            if (i != n - 1) ans.push_back(i);
        }
    }

    return ans;
}

};
