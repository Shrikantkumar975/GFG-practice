class Solution {
  public:
  
    void DFS(vector<vector<int>>&adj,int u,vector<int>&visited,vector<int>&res){
        if(visited[u]) return;
        
        visited[u]=true;
        res.push_back(u);
        
        for(auto &v : adj[u]){
            if(!visited[v]) DFS(adj,v,visited,res);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        
        vector<int> visited(adj.size(),0);
        vector<int> res;
        
        DFS(adj,0,visited,res);
        
        return res;
        
    }
};