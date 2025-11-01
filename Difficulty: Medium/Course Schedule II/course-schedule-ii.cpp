class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, 
                vector<int>& visited, vector<int>& stack) {
    
    // mark as visiting
    visited[node] = 1; 

    for (int neighbor : adj[node]) {
        if (visited[neighbor] == 1) {
            
            // cycle detected
            return false; 
        } else if (visited[neighbor] == 0) {
            if (!dfs(neighbor, adj, visited, stack)) {
                
                // cycle in deeper recursion
                return false; 
            }
        }
    }
    
    // mark as visited
    visited[node] = 2; 
    stack.push_back(node);
    return true;
}

// Function to find the topological order
vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (auto& pre : prerequisites) {
        int dest = pre[0];
        int src = pre[1];
        adj[src].push_back(dest);
    }
    
     // 0 = unvisited, 1 = visiting, 2 = visited
    vector<int> visited(n, 0);
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, adj, visited, stack)) {
                
                // cycle detected
                return {}; 
            }
        }
    }
    
    // reverse stack to get correct order
    reverse(stack.begin(), stack.end()); 
    return stack;
}
};