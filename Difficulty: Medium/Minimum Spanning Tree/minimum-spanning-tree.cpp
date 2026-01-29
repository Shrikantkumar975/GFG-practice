class Solution {
  public:
    using T = pair<int,int>;
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        // code here
        vector<bool> visited(V,false);
        
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,0});
        
        int ans=0;
        
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            
            if(visited[node]) continue;
            
            visited[node]=true;
            ans+=d;
            
            for(auto [v,dist]: adj[node]){
                // int v = neigh[0];
                // int dist = neigh[1];
                
                if(!visited[v]){
                    pq.push({dist,v});
                }
            }
        }
        
        return ans;
    }
};