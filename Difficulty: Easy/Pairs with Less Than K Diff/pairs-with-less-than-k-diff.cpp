class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        
        int ans=0;
        int j=0;
        
        for(int i=0;i<arr.size();i++){
            if (j < i + 1)
                j = i + 1;
            
            while(j<arr.size() && arr[j]-arr[i]<k){
                j++;
            }
            
            ans+=j-i-1;
        }
        
        return ans;
    }
};