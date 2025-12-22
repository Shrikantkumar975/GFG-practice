// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans=-1;
        int max = 0;
        
        for(int i=0;i<arr.size();i++){
            int sum = accumulate(arr[i].begin(),arr[i].end(),0);
            if(sum>max){
                max=sum;
                ans=i;
            }
        }
        return ans;
        
    }
    
};