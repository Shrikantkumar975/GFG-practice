class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
 
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank. resize(V);

        for(int i = 0; i<V; i++) {
            parent[i] = i;
            rank[i] = i;
        }
        // Code here
        
        for(int u=0;u<V;u++){
            for(int &v: adj[u]){
                if(v>u){
                    int parent_u = find(u);
                    int parent_v = find(v);
                    
                    if(parent_u == parent_v) return 1;
                    
                    Union(u,v);
                }
            }
        }
        return 0;
    }
};