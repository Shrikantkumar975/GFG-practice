class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int,int> mp;
        
        int sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += (a1[i] - a2[i]);
            
            // If prefix sum becomes 0
            if(sum == 0)
                maxLen = i + 1;
            
            // If seen before
            if(mp.find(sum) != mp.end()){
                maxLen = max(maxLen, i - mp[sum]);
            }
            else{
                mp[sum] = i; // store first occurrence
            }
        }
        
        return maxLen;
    }
};