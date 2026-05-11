class Solution {
  public:
    
    bool isPal(string &s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    bool palindromePair(vector<string>& arr) {
        
        unordered_map<string,int> mp;
        
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]] = i;
        }
        
        for(int i = 0; i < arr.size(); i++){
            
            string s = arr[i];
            int n = s.size();
            
            for(int j = 0; j <= n; j++){
                
                string left = s.substr(0, j);
                string right = s.substr(j);
                
                // left palindrome
                if(isPal(left, 0, left.size()-1)){
                    
                    string rev = right;
                    reverse(rev.begin(), rev.end());
                    
                    if(mp.count(rev) && mp[rev] != i)
                        return true;
                }
                
                // right palindrome
                if(j != n && isPal(right, 0, right.size()-1)){
                    
                    string rev = left;
                    reverse(rev.begin(), rev.end());
                    
                    if(mp.count(rev) && mp[rev] != i)
                        return true;
                }
            }
        }
        
        return false;
    }
};