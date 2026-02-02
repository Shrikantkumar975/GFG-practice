class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        
        int maxSum = arr[0], currMax = arr[0];
        int minSum = arr[0], currMin = arr[0];
        
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
            
            if (i > 0) {
                currMax = max(arr[i], currMax + arr[i]);
                maxSum = max(maxSum, currMax);
                
                currMin = min(arr[i], currMin + arr[i]);
                minSum = min(minSum, currMin);
            }
        }
        
        // If all elements are negative
        if (maxSum < 0)
            return maxSum;
        
        return max(maxSum, totalSum - minSum);
    }
};
