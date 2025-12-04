class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> result;
        vector<bool> visited(adj.size(),false);
        queue<int>q;
        
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            result.push_back(u);
            
            for(int v : adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
            
        }
        
        return result;
        
    }
};