class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> v(n+m-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i+j].push_back(mat[i][j]);
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<v.size();i++){
            for(int a: v[i]){
                ans.push_back(a);
            }
        }
        
        return ans;
        
    }
};