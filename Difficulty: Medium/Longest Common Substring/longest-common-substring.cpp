class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int m=s1.size();
        int n=s2.size();
        int maxi = 0;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    maxi = max(maxi,dp[i][j]);
                }
            }
        }
        
        return maxi;
    }
};