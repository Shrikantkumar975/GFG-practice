class Solution {
  public:
    vector<int> dx = {0,1,1,1,0,-1,-1,-1};
    vector<int> dy = {1,1,0,-1,-1,-1,0,1};
    void dfs(vector<vector<char>> &grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j] == 'W') return ;
        
        grid[i][j]='W';
        
        for(int k=0;k<8;k++)
            dfs(grid,i+dx[k],j+dy[k]);
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        
        
        return count;
        
    }
};