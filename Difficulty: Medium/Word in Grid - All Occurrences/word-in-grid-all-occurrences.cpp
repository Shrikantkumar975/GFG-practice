class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans;

        // 8 possible directions
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // First character must match
                if (mat[i][j] != word[0])
                    continue;

                // Try all 8 directions
                for (int d = 0; d < 8; d++) {

                    int x = i;
                    int y = j;
                    int k = 0;

                    // Check the complete word
                    while (k < word.size()) {

                        // Out of bounds
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            break;

                        // Character doesn't match
                        if (mat[x][y] != word[k])
                            break;

                        // Move to next character
                        x += dx[d];
                        y += dy[d];
                        k++;
                    }

                    // Complete word found
                    if (k == word.size()) {
                        ans.push_back({i, j});
                        break;  // avoid duplicate starting position
                    }
                }
            }
        }

        return ans;
    }
};