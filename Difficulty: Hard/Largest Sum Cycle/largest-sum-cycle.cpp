class Solution {
  public:
    int largestSumCycle(vector<int>& edge) {

        int n = edge.size();

        vector<int> vis(n, 0);
        vector<int> pos(n, -1);

        int ans = -1;

        for(int i = 0; i < n; i++) {

            if(vis[i]) continue;

            vector<int> path;
            int curr = i;

            while(curr != -1 && !vis[curr]) {

                vis[curr] = 1;
                pos[curr] = path.size();

                path.push_back(curr);

                curr = edge[curr];
            }

            // Cycle detected
            if(curr != -1 && pos[curr] != -1) {

                int sum = 0;

                for(int j = pos[curr]; j < path.size(); j++) {
                    sum += path[j];
                }

                ans = max(ans, sum);
            }

            // Reset current path positions
            for(int node : path) {
                pos[node] = -1;
            }
        }

        return ans;
    }
};