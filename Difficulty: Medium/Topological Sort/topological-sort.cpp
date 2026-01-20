class Solution {
  public:
  
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int u,stack<int> &st){
        visited[u]=true;
        
        for(int v: adj[u]){
            if(!visited[v]){
                dfs(adj,visited,v,st);
            }
        }
        st.push(u);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> st;
        
        vector<bool> visited(V,false);
        
        vector<vector<int>> adj(V);
        
        for(auto &node: edges){
            int u = node[0];
            int v = node[1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i])
                dfs(adj,visited,i,st);
        }
        
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};