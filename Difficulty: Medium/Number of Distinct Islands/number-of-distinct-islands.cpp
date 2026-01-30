// User function Template for C++

class Solution {
  public:
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    void dfs(vector<vector<int>> &grid,int i,int j,string &s,char ch){
        int n=grid.size();
        int m=grid[0].size();
        
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j] == 0) return ;
        
        s+=ch;
        grid[i][j]=0;
        
        dfs(grid,i+0,j+1,s,'R');
        dfs(grid,i+1,j,s,'D');
        dfs(grid,i,j-1,s,'L');
        dfs(grid,i-1,j,s,'U');
        
        s+='B';
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<string> st;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    string s="";
                    dfs(grid,i,j,s,'O');
                    st.insert(s);
                }
            }
        }
        
        
        return st.size();
    }
};
