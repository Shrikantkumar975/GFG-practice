class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int mod =0;
        
        for(char c: s){
            mod = (mod*10 + (c-'0'))%13;
        }
        
        return !mod;
    }
};