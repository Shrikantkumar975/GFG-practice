class Solution {
  public:
    int maxPerimeter(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        
        for(int i=arr.size()-3;i>=0;i--){
            if(arr[i] + arr[i+1] > arr[i+2])
                return arr[i]+arr[i+1]+arr[i+2];
        }
        
        return -1;
    }
};