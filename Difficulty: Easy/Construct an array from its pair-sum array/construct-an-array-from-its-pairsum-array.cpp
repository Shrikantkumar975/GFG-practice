class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        
        int m = arr.size();   // size of pair-sum array
        
        // Compute n using: m = n*(n-1)/2
        // Solve quadratic: n = (1 + sqrt(1 + 8*m)) / 2
        int n = (1 + sqrt(1 + 8LL * m)) / 2;

        vector<int> res(n);

        // Special case: only one pair: a + b = arr[0]
        if (n == 2) {
            res[0] = 1;
            res[1] = arr[0] - 1;
            return res;
        }

        // Find the first element a = res[0]
        long long a = (arr[0] + arr[1] - arr[n - 1]) / 2;
        res[0] = a;

        // Fill the rest: res[i] = arr[i-1] - a
        for (int i = 1; i < n; i++) {
            res[i] = arr[i - 1] - a;
        }

        return res;
    }
};
