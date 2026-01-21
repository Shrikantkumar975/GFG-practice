class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        
        for(auto &node : edges){
            adj[node[0]].push_back(node[1]);
            indegree[node[1]]++;
        }
        
        queue<int> q;
        int count=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            count++;
            
            for(int &v: adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0) q.push(v);
            }
        }
        
        return count!=V;
        
    }
};