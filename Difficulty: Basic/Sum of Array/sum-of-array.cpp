// User function template for C++
class Solution {
  public:
  int i=0;
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        if(i == arr.size()) return 0;
        
        return arr[i++] + arraySum(arr);
    }
};