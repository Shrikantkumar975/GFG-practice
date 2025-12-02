class Solution {
  public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
    int n = s.size();

    // jumps to the same char
    for (char ch = 'a'; ch <= 'z'; ch++) {
        jumps.push_back({ch, ch});
    }

    vector<vector<int>> nxtInd(n, vector<int>(26, -1));
    vector<int> lastInd(26, -1);

    // calculate next index of each character from index i
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++)
            nxtInd[i][j] = lastInd[j];

        lastInd[s[i] - 'a'] = i;
    }

    vector<vector<int>> child(26);

    // fill child array
    for (auto &jump : jumps) {
        char u = jump[0];
        char v = jump[1];
        child[u - 'a'].push_back(v);
    }

    vector<int> preScore(n + 1, 0);
  
    // computing prefix sum of ASCII values
    for (int i = 0; i < n; i++)
        preScore[i + 1] = preScore[i] + s[i];

    vector<int> dp(n, 0);

    // iterative DP from back to front
    for (int ind = n - 2; ind >= 0; ind--) {
        int score = 0;
        for (int it : child[s[ind] - 'a']) {
            int jmpInd = nxtInd[ind][it - 'a'];
            if (jmpInd == -1) continue;

            if (it == s[ind]) {
                int temp = preScore[jmpInd] - preScore[ind + 1] + dp[jmpInd];
                score = max(score, temp);
            } else {
                int temp = preScore[jmpInd] - preScore[ind] + dp[jmpInd];
                score = max(score, temp);
            }
        }
        dp[ind] = score;
    }

    return dp[0];
}
};