class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int i=0,zero=0,ans=0;
        
        for(int j=0;j<arr.size();j++){
            if(arr[j]==0) zero++;
            
            while(zero>k){
                if(arr[i]==0) zero--;
                i++;
            }
            
            ans= max(ans,j-i+1);
        }
        
        return ans;
    }
};
