class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // code here
        for(int i=1;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int maxi = 0;
                for(int k=0;k<m;k++){
                    if(k==j) continue;
                    maxi = max(maxi,mat[i-1][k]);
                }
                
                mat[i][j]+=maxi;
            }
        }
        
        int maxi=0;
        for(int i=0;i<mat[0].size();i++){
            maxi = max(maxi,mat[mat.size()-1][i]);
        }
        
        return maxi;
    }
};