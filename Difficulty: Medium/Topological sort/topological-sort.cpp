class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Initialize indegree array of all vertices with 0
        vector<int> indegree(V, 0);

        // Step 2: Create an adjacency list from the given edge list
        vector<vector<int>> adj(V);
        
        // Step 3: Convert edge list to adjacency list and compute indegree of each node
        for (auto& edge : edges) {
            int u = edge[0];         // edge from u
            int v = edge[1];         // to v (i.e., u → v)
            adj[u].push_back(v);     // add v to u's adjacency list
            indegree[v]++;           // increment indegree of v
        }
        
        // Step 4: Push all nodes with indegree 0 into the queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)    // node has no incoming edges
                q.push(i);           // it can be placed at the start of topo order
        }
        
        // Step 5: Perform BFS (Kahn's Algorithm)
        vector<int> topo;            // stores the final topological order
        while (!q.empty()) {
            int node = q.front();    // get the front node from queue
            q.pop();                 
            topo.push_back(node);    // add it to topological sort result
            
            // Reduce indegree of all its neighbors by 1
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;        // remove the edge node → neighbor
                if (indegree[neighbor] == 0) // if neighbor has no other incoming edges
                    q.push(neighbor);        // add it to the queue
            }
        }
        
        // Step 6: Check if a cycle exists
        // If the topological sort includes fewer than V nodes, a cycle exists
        if (topo.size() < V)
            return {};  // return empty vector to indicate that topological sort is not possible
        
        // Step 7: Return the topological sort result
        return topo;
    }
};
