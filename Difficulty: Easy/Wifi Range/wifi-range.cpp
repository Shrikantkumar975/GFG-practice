class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        
        
        int lastOne = -1;
        int i=0;
        while(i<s.size()){
            if(s[i]=='1'){
                lastOne =i;
                break;
            }
            i++;
        }
        
        if(i>=s.size() || s[i]!='1' || i>x) return false;
        
        for(;i<s.size();i++){
            if(s[i]=='0') continue;
            if(s[i]=='1' && (i-lastOne-1)>(2*x)){
                return false;
            }
            lastOne = i;
        }
        
        if(s.size()-lastOne-1 > x) return false;
        
        return true;
    }
};