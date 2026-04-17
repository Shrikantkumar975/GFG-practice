class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char,int> mpp;
    
        for(char c: s){
            mpp[c]++;
        }
        
        int count=0;
        
        for(auto &m: mpp){
            if(m.second%2!=0) count++;
        }
        
        if(count>1) return false;
        
        return true;
    }
};