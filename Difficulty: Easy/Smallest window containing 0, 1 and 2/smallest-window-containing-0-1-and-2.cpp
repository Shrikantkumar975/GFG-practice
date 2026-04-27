class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        vector<int> v(3,0);
        
        int i=0;
        int j=0;
        
        int ans=INT_MAX;
        
        while(j<s.size()){
            v[s[j]-'0']++;
            while(v[0]>0 && v[1]>0 && v[2]>0){
                ans = min(ans, j - i + 1);
                
                v[s[i] - '0']--;
                i++;
            }
            j++;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
