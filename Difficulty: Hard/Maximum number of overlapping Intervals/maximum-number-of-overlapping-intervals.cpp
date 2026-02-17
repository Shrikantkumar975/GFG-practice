class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        
        int maxTime = 0;
        
        // Find maximum ending time
        for (auto &interval : arr) {
            maxTime = max(maxTime, interval[1]);
        }
        
        // Create difference array
        vector<int> diff(maxTime + 2, 0);
        
        // Mark intervals
        for (auto &interval : arr) {
            diff[interval[0]] += 1;
            diff[interval[1] + 1] -= 1;
        }
        
        int curr = 0;
        int maxOverlap = 0;
        
        // Prefix sum
        for (int i = 0; i <= maxTime; i++) {
            curr += diff[i];
            maxOverlap = max(maxOverlap, curr);
        }
        
        return maxOverlap;
    }
};
