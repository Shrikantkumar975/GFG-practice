// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    // int findMaxSum(vector<int>& arr) {
    //     // code here
    //     vector<int> dp(arr.size());
        
    //     dp[0] = arr[0];
    //     dp[1] = max(arr[0],arr[1]);
        
    //     for(int i=2;i<arr.size();i++){
    //         dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
    //     }
        
    //     return dp[dp.size()-1];
    // }
    int findMaxSum(vector<int>& arr){
        arr[1] = max(arr[0],arr[1]);
        
        for(int i=2;i<arr.size();i++){
            arr[i] = max(arr[i-1],arr[i-2]+arr[i]);
        }
        
        return arr[arr.size()-1];
    }
};