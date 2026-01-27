class Solution {
  public:
    
    bool dfs(vector<vector<char>> &mat, string &word, int i, int j, int k) {
        // base case: whole word matched
        if(k == word.size()) return true;

        // boundary + character check
        if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size())
            return false;

        if(mat[i][j] != word[k])
            return false;

        char temp = mat[i][j];
        mat[i][j] = '#';   // mark visited

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        for(int d = 0; d < 4; d++) {
            if(dfs(mat, word, i + dx[d], j + dy[d], k + 1))
                return true;
        }

        mat[i][j] = temp;  // backtrack
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int n = mat.size(), m = mat[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(mat, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
