class Solution {
  public:
    bool dfs(vector<vector<int>>&mpp,vector<bool>&visited,int u,int parent){
        visited[u]=true;
        
        for(int &v:mpp[u]){
            if(v==parent) continue;
            
            if(visited[v]){
                return true;
            }
            
            if(dfs(mpp,visited,v,u)) return true;
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> mpp(V);
        
        
        for(auto m : edges){
            mpp[m[0]].push_back(m[1]);
            mpp[m[1]].push_back(m[0]);
        }
        
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(mpp,visited,i,-1)){
                return true;
            }
        }
        
        return false;
        
    }
};