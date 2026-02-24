class Solution {
  public:
    int memo[150][150];
    
    int solve(int i,int j, vector<int> &arr){
        
        if(i>=j) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int min_cost = INT_MAX;
        
        for(int k=i;k<j;k++){
            int cost = solve(i,k,arr) + solve(k+1,j,arr) + arr[i-1]*arr[k]*arr[j];
            
            min_cost = min(min_cost,cost);
        }
        
        memo[i][j] = min_cost;
        
        return memo[i][j];
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        memset(memo,-1,sizeof(memo));
        
        return solve(1,arr.size()-1,arr);
        
    }
};