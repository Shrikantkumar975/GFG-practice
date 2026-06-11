class Solution {
  public:
    int findIndex(string &s) {
        // code here
        vector<int> front(s.size(),0);
        vector<int> back(s.size(),0);
        
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            
            front[i]=open;
        }
        if(open==0) return s.size();
        
        int close=0;
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') close++;
            
            open -= (s[i] == '(');

            if(open == close)
                return i;
        }
        
        return ans;
    }
};