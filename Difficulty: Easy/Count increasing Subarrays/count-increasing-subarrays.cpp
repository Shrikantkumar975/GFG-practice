class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size();
        int len = 1;   // current increasing segment length
        int ans = 0;

        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1]) {
                len++;  // still increasing
            } else {
                // segment ended
                if(len >= 2) {
                    ans += (len * (len - 1)) / 2;
                }
                len = 1; // reset
            }
        }

        // last segment
        if(len >= 2) {
            ans += (len * (len - 1)) / 2;
        }

        return ans;
        
    }
};
