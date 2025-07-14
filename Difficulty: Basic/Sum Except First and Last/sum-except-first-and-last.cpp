class Solution {
  public:
    /*You are required to complete this method*/
    int sumExceptFirstLast(vector<int>& arr) {
        // Your code here
        int sum = accumulate(arr.begin(),arr.end(),0);
        
        return sum - arr[0] - arr[arr.size()-1];
    }
};