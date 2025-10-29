class Solution {
  public:
    pair<int, int> bfs(int start_node, int n, const vector<vector<int>>& adj) {
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start_node);
        dist[start_node] = 0;

        int farthest_node = start_node;
        int max_dist = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > max_dist) {
                max_dist = dist[u];
                farthest_node = u;
            }

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return {farthest_node, max_dist};
    }

    int diameter(int V, vector<vector<int>>& edges) {
        if (V == 0) {
            return 0;
        }
        if (V == 1) {
            return 0;
        }

        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 1: Find one endpoint of the diameter
        pair<int, int> result1 = bfs(0, V, adj);
        int farthest_node_from_arbitrary = result1.first;

        // Step 2: Find the other endpoint and the diameter
        pair<int, int> result2 = bfs(farthest_node_from_arbitrary, V, adj);
        int diameter_value = result2.second;

        return diameter_value;
    }
};
