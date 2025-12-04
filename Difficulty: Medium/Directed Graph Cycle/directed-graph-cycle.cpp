class Solution {
  public:
    bool dfs(vector<vector<int>>&adj,vector<bool>&visited,int u,vector<bool>&inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        
        for(int v: adj[u]){
            if(!visited[v] && dfs(adj,visited,v,inRecursion)){
                return true;
            }
            else if(inRecursion[v]){
                return true;
            }
        }
        inRecursion[u]=false;
        return false;
    }
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto m: edges){
            adj[m[0]].push_back(m[1]);
        }
        
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,i,inRecursion)){
                    return true;
                }
            }
        }
        
        return false;
    }
};