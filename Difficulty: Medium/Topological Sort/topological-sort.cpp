class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        
        for(auto m: edges){
            adj[m[0]].push_back(m[1]);
            indegree[m[1]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> result;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            result.push_back(u);
            
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        
        return result;
    }
};