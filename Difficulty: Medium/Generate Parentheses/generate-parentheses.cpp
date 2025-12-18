// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  public:
    
    void gen(vector<string>&ans,string s,int open,int close,int n){
        if(close == n) ans.push_back(s);
        
        if(open<n) gen(ans,s+'(',open+1,close,n);
        if(close<open) gen(ans,s+')',open,close+1,n);
    }
    
  
    vector<string> generateParentheses(int n) {
        // code here
        n/=2;
        
        vector<string> ans;
        
        gen(ans,"",0,0,n);
        
        return ans;
    }
};