class Solution {
  public:
    vector<int> di = {-2,-2,-1,1,2,2,1,-1};
    vector<int> dj = {1,-1,2,2,1,-1,-2,-2};
    
    int numOfWays(int n, int m) {
        // code here
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=0;k<8;k++){
                    if(i+di[k]<n && i+di[k]>=0 && j+dj[k]<m && j+dj[k]>=0) count++;
                }
                
                ans+=n*m-1-count;
            }
        }
        
        return ans;
    }
};