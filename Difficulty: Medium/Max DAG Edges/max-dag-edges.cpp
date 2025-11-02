class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build adjacency list and indegree array
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // Topological sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        // Map node → its position in topological order
        vector<int> pos(V);
        for (int i = 0; i < V; i++) pos[topo[i]] = i;

        // Mark existing edges
        vector<vector<bool>> hasEdge(V, vector<bool>(V, false));
        for (auto& e : edges) {
            hasEdge[e[0]][e[1]] = true;
        }

        // Count how many edges can still be added
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int u = topo[i];
                int v = topo[j];
                if (!hasEdge[u][v]) count++;
            }
        }

        return count;
    }
};
