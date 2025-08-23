class Solution {
  public:
    
    void BFS(vector<vector<int>> &adj,int u,vector<int> &visited,vector<int>&res){
        queue<int> q;
        q.push(u);
        visited[u] = true;
        res.push_back(u);
        
        while(!q.empty()){
            u=q.front();
            q.pop();
            for(int v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                    res.push_back(v);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> visited(adj.size(),0);
        vector<int> res;
        
        BFS(adj,0,visited,res);
        
        return res;
    }
};