class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int zeros_after = 0;
        
        // Count the total number of 0s in the array
        for (int num : arr) {
            if (num == 0) {
                zeros_after++;
            }
        }
        
        int ones_before = 0;
        int min_toggles = zeros_after; // Baseline: entire array becomes 1s
        
        // Move the partition point across the array
        for (int num : arr) {
            if (num == 0) {
                zeros_after--;
            } else {
                ones_before++;
            }
            
            // Track the minimum toggles seen so far
            min_toggles = min(min_toggles, ones_before + zeros_after);
        }
        
        return min_toggles;
    }
};
