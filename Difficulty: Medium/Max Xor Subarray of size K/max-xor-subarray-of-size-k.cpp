class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        for(int i=1;i<arr.size();i++){
            arr[i]^=arr[i-1];
        }
        
        int maxi = arr[k-1];
        
        for(int i=k;i<arr.size();i++){
            maxi = max(maxi,arr[i]^arr[i-k]);
        }
        
        return maxi;
    }
};