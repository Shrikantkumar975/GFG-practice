class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int,int> mp;
        long ans = 0;
        int px = 0;   // prefix xor
        
        mp[0] = 1;    // important
        
        for(int i = 0; i < arr.size(); i++) {
            px ^= arr[i];   // update prefix xor
            
            if(mp.find(px ^ k) != mp.end()) {
                ans += mp[px ^ k];
            }
            
            mp[px]++;  // store prefix
        }
        
        return ans;
    }
};