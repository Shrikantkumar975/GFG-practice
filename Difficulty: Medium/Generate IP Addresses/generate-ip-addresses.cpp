class Solution {
  public:
  int n ;
  vector<string>res;
  bool isvalid(string str){
      if(str[0] == '0' && str.size() > 1) return false;
      int val = stoi(str);
      if(val > 255) return false;
      return true;
  }
  void solve(string &s , int i , int path , string curr){
      if(i == n && path == 4){
          curr.pop_back();
          res.push_back(curr);
          return ;
      }
      if(i+1 <= n && isvalid(s.substr(i , 1))){
          solve(s , i+1 , path+1 , curr+s.substr(i , 1) + ".");
      }
      if(i+2 <= n && isvalid(s.substr(i , 2))){
          solve(s , i+2 , path+1 , curr+s.substr(i , 2) + ".");
      }
      if(i+3 <= n && isvalid(s.substr(i , 3))){
          solve(s , i+3 , path+1 , curr+s.substr(i , 3) + ".");
      }
  }
    vector<string> generateIp(string &s) {
        // code here
        n = s.size();
        if( n> 12) return res;
        solve( s , 0 , 0 , "");
        return res;
    }
};