// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int INF =1e8;
        vector<int> distance(V,INF);
        distance[src] = 0;
        
        for(int i=0;i<V;i++){
            for(auto &edge: edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                
                if(distance[u]!=INF && distance[u]+w < distance[v]){
                    distance[v]=distance[u]+w;
                }
            }
        }
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            
            if(distance[u]!=INF && distance[u]+w < distance[v]){
                return {-1};
            }
        }
        
        return distance;
    }
};
