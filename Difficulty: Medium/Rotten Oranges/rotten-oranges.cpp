class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // code here
        int fresh=0;
        int rotten=0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    fresh++;
                }else if(mat[i][j]==2) q.push({i,j});
            }
        }
        
        if(fresh==0) return 0;
        
        if(q.size()==0) return -1;
        
        int ans=0;
        
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    if(x+dx[i]<m && x+dx[i]>=0 && y+dy[i]<n && y+dy[i]>=0 && mat[x+dx[i]][y+dy[i]]==1){
                        fresh--;
                        mat[x+dx[i]][y+dy[i]]=2;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
                
            }
        }
        
        if(fresh!=0) return -1;
        
        return ans-1;
    }
};