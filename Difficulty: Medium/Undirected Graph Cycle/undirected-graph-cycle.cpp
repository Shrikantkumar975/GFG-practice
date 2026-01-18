class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto &u: edges){
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        
        vector<int> visited(V,false);
        queue<pair<int,int>> q;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                q.push({i,-1});
                visited[i]=true;
                
                while(!q.empty()){
                    auto [node,parent] = q.front();
                    q.pop();
                    
                    for(auto &v: adj[node]){
                        if(!visited[v]){
                            q.push({v,node});
                            visited[v]=true;
                        }else if(v != parent){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};