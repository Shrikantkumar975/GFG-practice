class Solution {
  public:
    void DFS(vector<int> adj[],int u,vector<bool> &visited){
        visited[u]=true;
        
        for(auto it = adj[u].begin();it!=adj[u].end();it++){
            int neighbor = *it;
            
            if(visited[neighbor] == false){
                DFS(adj,neighbor,visited);
            }
        }
    }
  
    bool isConnected(int V , vector<int> adj[]){
        
        int nZDV = -1;
        
        for(int i=0;i<V;i++){
            if(adj[i].size() != 0){
                nZDV = i;
                break;
            }
        }
        
        vector<bool> visited(V,0);
        
        DFS(adj,nZDV,visited);
        
        for(int i=0;i<V;i++){
            if(visited[i]==false && adj[i].size() !=0){
                return false;
            }
        }
        
        return true;
    }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        if(isConnected(V,adj) == false) return 0;
        
        int oddDegree =0;
        
        for(int i=0;i<V;i++){
            if(adj[i].size()%2 != 0) oddDegree++;
        }
        
        if(oddDegree == 0) return 2;
        
        if(oddDegree == 2) return 1;
        
        return 0;
        
    }
};