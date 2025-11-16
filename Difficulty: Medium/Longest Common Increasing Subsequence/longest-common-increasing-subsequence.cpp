class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();

    // dp[j] stores the length of LCIS ending at b[j]
    vector<int> dp(n, 0);

    // Traverse each element of array a
    for (int i = 0; i < m; i++) {
        int currentLength = 0;

        // Compare current element of a with all elements of b
        for (int j = 0; j < n; j++) {

            //When elements match, extend the LCIS
            if (a[i] == b[j]) {
                dp[j] = max(dp[j], currentLength + 1);
            }

            // If a[i] is greater, update best LCIS so far
            else if (a[i] > b[j]) {
                currentLength = max(currentLength, dp[j]);
            }

        }
    }

    // The maximum value in dp gives final LCIS length
    return *max_element(dp.begin(), dp.end());
}
};