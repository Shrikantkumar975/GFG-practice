class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Update heights for current row
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // IMPORTANT: don't sort height directly
            vector<int> temp = height;

            // Sort heights in descending order
            sort(temp.begin(), temp.end(), greater<int>());

            // Calculate maximum rectangle
            for (int j = 0; j < m; j++) {
                int width = j + 1;
                int area = temp[j] * width;
                ans = max(ans, area);
            }
        }

        return ans;
    }
};