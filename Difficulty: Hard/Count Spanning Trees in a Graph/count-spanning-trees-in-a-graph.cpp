class Solution {
  public:
  
    long long determinant(vector<vector<double>> mat, int n) {
        
        double det = 1;

        for (int i = 0; i < n; i++) {

            int pivot = i;

            while (pivot < n && abs(mat[pivot][i]) < 1e-9)
                pivot++;

            if (pivot == n)
                return 0;

            if (pivot != i) {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < n; j++) {

                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {
        
        if (n == 1)
            return 1;

        vector<vector<double>> lap(n, vector<double>(n, 0));

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        vector<vector<double>> minor(n - 1, vector<double>(n - 1));

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                minor[i - 1][j - 1] = lap[i][j];
            }
        }

        return determinant(minor, n - 1);
    }
};