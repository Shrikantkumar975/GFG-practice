class Solution {
  public:
    int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();

    // If we can't merge all piles 
    // into one pile, return -1
    if ((n - 1) % (k - 1) != 0) return -1;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Compute prefix sums 
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + stones[i];
    }
        
    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            int minCost = INT_MAX;
            
            // Try merging stones in groups of k-1 intervals
            for(int idx = i; idx < j; idx += k-1) {
                int cost = dp[i][idx] + dp[idx+1][j];
                minCost = min(cost, minCost);
            }

            // If we can merge these piles 
            // into one, add total sum cost
            if((j-i)%(k-1) == 0){
                minCost += prefixSum[j+1] - prefixSum[i];
            }
            dp[i][j] = minCost;
        }
    }
        
    return dp[0][n-1];
}

};