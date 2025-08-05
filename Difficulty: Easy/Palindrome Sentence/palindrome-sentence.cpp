class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string s1="";
        
        for(int i=0;i<s.size();i++){
           if (isalpha(s[i])) {
               s1.push_back(tolower(s[i]));
           }else if(isdigit(s[i])){
               s1.push_back(s[i]);
           }
        }
        
        int i=0,j=s1.size()-1;
        
        while(i<j){
            if(s1[i]!=s1[j]) return false;
            i++;
            j--;
        }
        
        return true;
        
    }
};