class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> dist(V,0);
        
        for(int i=0;i<V;i++){
            int updated = 0;
            
            
            for(auto &e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u]+w;
                    updated = 1;
                    
                    if(i==V-1) return true;
                }
                
            }
            if(!updated){
                return false;
            }
        }
        
        return false;
    }
};