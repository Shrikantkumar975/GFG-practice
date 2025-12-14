class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));

        pref[0][0] = mat[0][0];
        for(int i = 1; i < n; i++) pref[i][0] = pref[i-1][0] + mat[i][0];
        for(int j = 1; j < m; j++) pref[0][j] = pref[0][j-1] + mat[0][j];

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                pref[i][j] = mat[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        vector<int> ans;
        for(auto &q : queries){
            int a = q[0], b = q[1], c = q[2], d = q[3];
            int sum = pref[c][d];
            if(a > 0) sum -= pref[a-1][d];
            if(b > 0) sum -= pref[c][b-1];
            if(a > 0 && b > 0) sum += pref[a-1][b-1];
            ans.push_back(sum);
        }

        return ans;
    }
};
