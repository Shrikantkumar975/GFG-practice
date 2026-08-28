class Solution {
    public:
      int minCost(vector<vector<int>>& mat) {
          int n = mat.size();

          // First row
          int dp0 = mat[0][0];
          int dp1 = mat[0][1];
          int dp2 = mat[0][2];

          for (int i = 1; i < n; i++) {
              int new0 = mat[i][0] + min(dp1, dp2);
              int new1 = mat[i][1] + min(dp0, dp2);
              int new2 = mat[i][2] + min(dp0, dp1);

              dp0 = new0;
              dp1 = new1;
              dp2 = new2;
          }

          return min({dp0, dp1, dp2});
      }
  };