class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        
        unordered_map<int, int> mp;
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            
            // Convert to +1 and -1
            if(arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1;
            
            // If sum > 0 → whole subarray valid
            if(prefixSum > 0)
                maxLen = i + 1;
            
            else {
                // Check if (prefixSum - 1) seen before
                if(mp.find(prefixSum - 1) != mp.end()) {
                    maxLen = max(maxLen, i - mp[prefixSum - 1]);
                }
            }
            
            // Store first occurrence only
            if(mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};