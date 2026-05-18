class Solution {
  public:
    int maxSum(int n) {
        vector<int> arr(n+1,0);
    
        for(int i=0;i<=n;i++){
            arr[i] = max(i,arr[i/2]+ arr[i/3] + arr[i/4]);
        }
        
        return arr[n];
    }
};