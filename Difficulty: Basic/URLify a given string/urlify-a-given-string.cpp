class Solution {
  public:
    string URLify(string &s) {
        // code here
        string s1 = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                s1+="%20";
            }else s1+=s[i];
        }
        
        return s1;
    }
};