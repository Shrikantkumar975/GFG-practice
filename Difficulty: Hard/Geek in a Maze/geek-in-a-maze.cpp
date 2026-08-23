class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#')
            return 0;

        // dist[i][j] = minimum number of upward moves
        // required to reach (i, j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;

        dist[r][c] = 0;
        q.push({r, c});

        int ans = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            int up = dist[x][y];

            // Number of downward moves used
            int down = up + (x - r);

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (mat[nx][ny] == '#')
                    continue;

                int newUp = up;

                // Moving upward consumes one upward move
                if (nx < x)
                    newUp++;

                // Downward moves after reaching nx
                int newDown = newUp + (nx - r);

                if (newUp > u || newDown > d)
                    continue;

                // We only need the minimum upward moves
                if (newUp < dist[nx][ny]) {
                    if (dist[nx][ny] == INT_MAX)
                        ans++;

                    dist[nx][ny] = newUp;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};