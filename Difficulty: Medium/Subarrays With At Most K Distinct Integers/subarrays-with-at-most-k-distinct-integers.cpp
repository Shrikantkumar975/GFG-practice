class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        
        int left = 0;
        long long ans = 0;
        
        for (int right = 0; right < n; right++) {
            freq[arr[right]]++;
            
            // shrink window if distinct > k
            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                    freq.erase(arr[left]);
                left++;
            }
            
            // all subarrays ending at 'right'
            ans += (right - left + 1);
        }
        
        return ans;
    }
};
