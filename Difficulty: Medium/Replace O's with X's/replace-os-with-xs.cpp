class Solution {
  public:
    
    void dfs(vector<vector<char>>& grid,int i,int j){
        if((i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1) || grid[i][j]!='O'){
            return;
        }
        
        grid[i][j]='1';
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    
    void fill(vector<vector<char>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1 && grid[i][j]=='O'){
                    dfs(grid,i,j);
                }
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='1') grid[i][j]='O';
            }
        }
        
    }
};