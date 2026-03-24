class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Code here
        vector<vector<int>> adj(n);
        
        vector<int> indegree(n);
        queue<int> q;
        
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int ans=0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            ans++;
            
            for(auto v: adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        
        return ans==n;
    }
};