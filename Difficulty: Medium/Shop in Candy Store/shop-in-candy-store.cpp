class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
  
    // Sort the array to arrange candies by price
    sort(prices.begin(), prices.end());
    
    // Calculate minimum cost by traversing from beginning
    int n = prices.size();
    int minCost = 0;
    for (int i = 0; i < n; i++) {
        minCost += prices[i];
        n -= k;
    }

    // Calculate maximum cost by traversing from end
    int index = -1, maxCost = 0; 
    for (int i = prices.size() - 1; i > index; i--) {
        maxCost += prices[i];
        index += k;
    }

    return {minCost, maxCost};
}
};