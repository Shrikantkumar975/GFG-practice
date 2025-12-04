class Solution {
  public:
  
    void DFS(vector<vector<int>>&adj,int u,vector<bool>&visited,vector<int>&result){
        if(visited[u]) return;
        
        result.push_back(u);
        visited[u]=true;
        
        for(int v:adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,result);
            }
        }
        
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size(),false);
        
        vector<int> result;
        
        DFS(adj,0,visited,result);
        
        return result;
    }
};