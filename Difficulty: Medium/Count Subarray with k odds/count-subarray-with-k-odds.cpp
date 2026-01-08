class Solution {
  public:
    // Helper function to count subarrays with at most 'goal' odd numbers
    int countAtMost(vector<int>& arr, int goal) {
        if (goal < 0) return 0;
        
        int left = 0;
        int current_odd_count = 0;
        int total_subarrays = 0;
        
        for (int right = 0; right < arr.size(); right++) {
            // If the current element is odd, increment our window counter
            if (arr[right] % 2 != 0) {
                current_odd_count++;
            }
            
            // If we exceed our goal, shrink the window from the left
            while (current_odd_count > goal) {
                if (arr[left] % 2 != 0) {
                    current_odd_count--;
                }
                left++;
            }
            
            // The number of subarrays ending at 'right' with at most 'goal' odds
            // is equal to the length of the current valid window.
            total_subarrays += (right - left + 1);
        }
        
        return total_subarrays;
    }

    int countSubarrays(vector<int>& arr, int k) {
        // Exactly K = (At most K) - (At most K-1)
        return countAtMost(arr, k) - countAtMost(arr, k - 1);
    }
};