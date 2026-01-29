// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        const int INF = 1e8;
        
        for(int k=0;k<dist.size();k++){
            for(int i=0;i<dist.size();i++){
                for(int j=0;j<dist.size();j++){
                    if(dist[i][k]<INF && dist[k][j]<INF){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
    }
};