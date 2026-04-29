class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: count total 1s
        int ones = 0;
        for(int x : arr) {
            if(x == 1) ones++;
        }
        
        // Step 2: edge case
        if(ones == 0) return -1;
        
        // Step 3: count zeros in first window
        int zeros = 0;
        for(int i = 0; i < ones; i++) {
            if(arr[i] == 0) zeros++;
        }
        
        int ans = zeros;
        
        // Step 4: sliding window
        for(int i = ones; i < n; i++) {
            if(arr[i] == 0) zeros++;                 // new element
            if(arr[i - ones] == 0) zeros--;          // remove old
            
            ans = min(ans, zeros);
        }
        
        return ans;
    }
};