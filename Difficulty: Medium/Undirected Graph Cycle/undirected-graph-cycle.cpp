class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh, node, adj, visited))
                    return true;
            } else if (neigh != parent) {
                // Visited neighbor that's not the parent => cycle
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // since undirected
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) {
                    return true; // cycle found
                }
            }
        }

        return false; // no cycle
    }
};
