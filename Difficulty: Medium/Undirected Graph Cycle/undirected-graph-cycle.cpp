class Solution {
  public:
    bool DFS(vector<vector<int>>&adj,vector<int>&visited,int u,int parent){
        
        visited[u]=true;
        
        for(int v: adj[u]){
            if(!visited[v]){
                if(DFS(adj,visited,v,u)) return true;
            }
            else if(v != parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(adj.size(),0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(DFS(adj,visited,i,-1)) return true;
            }
        }
        
        return false;
    }
};