class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();

        int arrSum = 0;
        int currVal = 0;

        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += i * arr[i];
        }

        int res = currVal;

        for (int i = 1; i < n; i++) {
            currVal = currVal + arrSum - n * arr[n - i];
            res = max(res, currVal);
        }

        return res;
    }
};
