class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> m;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m.push_back(mat[i][j]);
            }
        }
        
        sort(m.begin(),m.end());
        
        return m[m.size()/2];
    }
};
