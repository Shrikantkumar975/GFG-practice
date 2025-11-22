class Solution {
public:

    void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[start] = true;
        for (int neighbor : adj[start]) {
            if (!visited[neighbor])
                dfs(neighbor, adj, visited);
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        
        // Build adjacency list from edges array
        // edges[i] = {u, v}
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        int edgesCount = 0;

        // Count edges
        for (int i = 0; i < V; i++)
            edgesCount += adj[i].size();

        edgesCount /= 2; // undirected graph

        // Count connected components using DFS
        int components = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        // If edges less than V - 1, impossible to connect fully
        if (edgesCount < V - 1)
            return -1;

        // Extra edges
        int extra = edgesCount - (V - components);

        // Check if extra edges can connect all components
        if (extra >= (components - 1))
            return components - 1;

        return -1;
    }
};
