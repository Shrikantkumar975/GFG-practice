class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') s[j++]=s[i];
        }
        
        return s.substr(0,j);
    }
};