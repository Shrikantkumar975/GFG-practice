class Solution {
  public:
     vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        // Build adjacency list from edge list
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        // Build reversed graph
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }
        
        // Queue for nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        // Kahn's algorithm (Topological Sort)
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        
        sort(safe.begin(), safe.end());
        return safe;
    }
};