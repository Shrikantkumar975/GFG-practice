class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefEven(n+1, 0), prefOdd(n+1, 0);

        for(int i = 0; i < n; i++){
            prefEven[i+1] = prefEven[i];
            prefOdd[i+1] = prefOdd[i];
            if(i % 2 == 0) prefEven[i+1] += arr[i];
            else prefOdd[i+1] += arr[i];
        }

        int totalEven = prefEven[n];
        int totalOdd = prefOdd[n];
        int ans = 0;

        for(int i = 0; i < n; i++){
            int evenSum = prefEven[i] + (totalOdd - prefOdd[i+1]);
            int oddSum  = prefOdd[i] + (totalEven - prefEven[i+1]);
            if(evenSum == oddSum) ans++;
        }

        return ans;
    }
};
