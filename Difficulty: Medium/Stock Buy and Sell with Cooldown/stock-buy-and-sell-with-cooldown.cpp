class Solution {
  public:
    int maxProfit(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> ahead1(2, 0), ahead2(2, 0), curr(2, 0);

    for (int i = n - 1; i >= 0; i--) {

        // When we can buy
        curr[1] = max(-arr[i] + ahead1[0], ahead1[1]);

        // When we can sell
        curr[0] = max(arr[i] + ahead2[1], ahead1[0]);

        ahead2 = ahead1;
        ahead1 = curr;
    }

    return ahead1[1];
}
};