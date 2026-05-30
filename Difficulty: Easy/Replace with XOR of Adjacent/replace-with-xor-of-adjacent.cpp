class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        vector<int> ans=arr;
        
        ans[0]=arr[0]^arr[1];
        for(int i=1;i<arr.size()-1;i++){
            ans[i]=arr[i-1]^arr[i+1];
        }
        
        ans[arr.size()-1]=arr[arr.size()-1]^arr[arr.size()-2];
        
        arr=ans;
    }
};