class Solution {
  public:
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    
    void dfs(vector<vector<int>>&grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        
        grid[i][j]=0;
        
        for(int k=0;k<4;k++){
            dfs(grid,i+dx[k],j+dy[k]);
        }
    }
    
    void dfs(vector<vector<int>>&grid, int i, int j,int &count){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        
        grid[i][j]=0;
        count++;
        
        for(int k=0;k<4;k++){
            dfs(grid,i+dx[k],j+dy[k],count);
        }
    }
    
    int cntOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // code here
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1){
                    dfs(grid,i,j);
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int count=0;
                if(grid[i][j]==1){
                    dfs(grid,i,j,count);
                }
                ans +=count;
            }
        }
        
        return ans;
    }
};