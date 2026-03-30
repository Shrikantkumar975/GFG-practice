class Solution {
  public:
    using P = pair<int,int>;
    int minCost(vector<vector<int>>& points) {
        int V =points.size(); 
        vector<vector<pair<int,int>>> adj(V); 
        for(int i=0;i<V-1;i++){ 
            for(int j=i+1;j<V;j++){ 
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j,d}); 
                adj[j].push_back({i,d}); 
            } 
        } 
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<bool> visited(V,false); 
        pq.push({0,0}); 
        int sum=0; 
        while(!pq.empty()){ 
            auto [d,u] = pq.top(); 
            pq.pop(); 
            if(visited[u]) continue; 
            visited[u]=true; 
            sum+=d; 
            for(auto [v,w] : adj[u]){ 
                if(!visited[v]){ 
                    pq.push({w,v}); 
                }
            } 
        } 
        return sum;
    }
};