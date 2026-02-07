class Solution {
  public:
    int check(vector<int> &arr,int mid){
        int curr=1;
        int currSum=0;
        
        for(int a : arr){
            if(currSum+a>mid){
                curr++;
                currSum=a;
            }else{
                currSum+=a;
            }
        }
        
        return curr;
    }
  
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size()) return -1;
        // code here
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        
        int ans= -1;
        
        while(low<=high){
            int mid = (low + high)/2;
            
            if(check(arr,mid)<=k){
                ans = mid;
                high = mid-1;
            }
            else low= mid+1;
        }
        
        return ans;
        
    }
};