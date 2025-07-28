class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v =edges[i][1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int size = q.size();
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        
        if(topo.size() < V) return {};
        
        return topo;
    }
};