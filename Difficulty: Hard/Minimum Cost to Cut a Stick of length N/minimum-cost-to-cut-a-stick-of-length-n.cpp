class Solution {
  public:
    int minCutCost(int n, vector<int> &cuts) {

    // Add boundaries 0 and n to represent stick ends
    cuts.push_back(0);
    cuts.push_back(n);

    // Sort to ensure segments are in proper order
    sort(cuts.begin(), cuts.end());

    int sz = cuts.size();

    vector<vector<int>> dp(sz, vector<int>(sz, 0));

    for (int len = 2; len < sz; len++) {
        for (int left = 0; left + len < sz; left++) {
            int right = left + len;
            int minCost = INT_MAX;

            // Explore all possible cuts between left and right
            for (int i = left + 1; i < right; i++) {
                int cost = cuts[right] - cuts[left] + dp[left][i] + dp[i][right];
                minCost = min(minCost, cost);
            }

            // Store the minimum cost for this segment
            dp[left][right] = (minCost == INT_MAX) ? 0 : minCost;
        }
    }

    // Final result is the cost to cut the full stick (0 to sz - 1)
    return dp[0][sz - 1];
}
};