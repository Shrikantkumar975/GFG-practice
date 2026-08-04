class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int ans=0;
        
        for(int i=0;i<arr.size()-1;i++){
            int low = i+1;
            int high = arr.size()-1;
            int curr=i;
            
            while(low<=high){
                int mid = (low+high)/2;
                
                if(arr[mid]-arr[i] < k){
                    curr=mid;
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            
            ans+=curr-i;
        }
        
        return ans;
    }
};