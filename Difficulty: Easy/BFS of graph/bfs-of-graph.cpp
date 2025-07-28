class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<int> vis(adj.size(),0);
        vis[0]=1;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            
            q.pop();
            
            for(int neigh : adj[node]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh]=1;
                }
            }
        }
        
        return ans;
    }
};