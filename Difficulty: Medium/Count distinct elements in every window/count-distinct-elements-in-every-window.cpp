class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        
        // Process first window
        for (int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        result.push_back(freq.size());
        
        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            // Remove outgoing element
            freq[arr[i - k]]--;
            if (freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);
            }
            
            // Add incoming element
            freq[arr[i]]++;
            
            result.push_back(freq.size());
        }
        
        return result;
    }
};
