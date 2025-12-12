class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>> v=mat;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                v[j][i] = mat[i][j];
            }
        }
        
        return v;
    }
};