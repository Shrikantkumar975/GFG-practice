class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        
        int maxi = arr[k-1];
        
        for(int j=k;j<arr.size();j++){
            maxi = max(maxi,arr[j]-arr[j-k]);
        }
        
        return maxi;
    }
};