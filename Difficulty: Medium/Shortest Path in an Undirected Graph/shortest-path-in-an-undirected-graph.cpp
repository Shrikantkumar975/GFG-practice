class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        const int INF=1e9+7;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        vector<int> distance(n+1,INF);
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        q.push({0,1});
        distance[1]=0;
        
        while(!q.empty()){
            auto [d,node] = q.top();
            q.pop();
            
            for(auto [v,dist]: adj[node]){
                if(d+dist < distance[v]){
                    parent[v]=node;
                    distance[v]=d+dist;
                    q.push({d+dist,v});
                }
            }
        }
        
        if(distance[n] == INF) return {-1};
        
        vector<int> path;
        int curr=n;
        // path.push_back(distance[n]);
        path.push_back(curr);
        while(parent[curr]!=curr){
            path.push_back(parent[curr]);
            curr = parent[curr];
        }
        
        
        vector<int> ans;
        ans.push_back(distance[n]);
        reverse(path.begin(),path.end());
        for(int &a: path){
            ans.push_back(a);
        }
        
        return ans;
        
    }
};