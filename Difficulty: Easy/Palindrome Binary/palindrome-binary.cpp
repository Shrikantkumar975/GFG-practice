class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string s="";
        
        while(n){
            s+=n%2==0?'0':'1';
            n/=2;
        }
        
        string s1=s;
        
        reverse(s1.begin(),s1.end());
        
        return s1==s;
    }
};