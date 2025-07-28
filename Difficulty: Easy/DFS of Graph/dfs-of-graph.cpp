class Solution {
  public:
    void helper(vector<vector<int>> adj,vector<int>&visited,vector<int>&ans,int node){
        visited[node]=1;
        ans.push_back(node);
        
        for(int neigh : adj[node]){
            if(!visited[neigh]) helper(adj,visited,ans,neigh);
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> visited(adj.size(),0);
        vector<int> ans;
        
        helper(adj,visited,ans,0);
        
        return ans;
    }
};