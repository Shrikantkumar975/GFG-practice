class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
    int m = mat[0].size();
    
    // diff matrix of size n x m 
    vector<vector<int>> diff(n, vector<int>(m, 0));
    
    // apply all operations using 4-point updates
    for (auto& q : opr) {
        int v = q[0];
        int r1 = q[1], c1 = q[2], r2 = q[3], c2 = q[4];
         
        // top-left -> add
        diff[r1][c1] += v;
        
        // top-right -> subtract
        if (c2 + 1 < m) diff[r1][c2 + 1] -= v;
        
        // bottom-left -> subtract
        if (r2 + 1 < n) diff[r2 + 1][c1] -= v;
        
        // bottim-right -> add
        if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
    }
    
    // row-wise prefix sum
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            diff[i][j] += diff[i][j - 1];
        }
    }
    
    // column-wise prefix sum
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            diff[i][j] += diff[i - 1][j];
        }
    }
    
    // apply diff to original matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] += diff[i][j];
        }
    }
    
    return mat;
    }
};