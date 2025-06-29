class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int x=0,n=arr.size()+1;
        for(int i=0;i<arr.size();++i) x^=arr[i]^(i+1);
        return x^n;
    }
};