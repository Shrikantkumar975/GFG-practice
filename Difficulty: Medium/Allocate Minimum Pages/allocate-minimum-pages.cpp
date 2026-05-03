class Solution {
  public:
    int check(vector<int> &arr,int mid){
        int pages=arr[0];
        int count=1;
        
        for(int i=1;i<arr.size();i++){
            if(pages+arr[i]<=mid){
                pages+=arr[i];
            }else{
                count++;
                pages=arr[i];
            }
        }
        
        return count;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int  n = arr.size();
        
        if(k>n) return -1;
        
        int ans =-1;
        
        int high = accumulate(arr.begin(),arr.end(),0);
        int low = *max_element(arr.begin(),arr.end());
        
        while(low<=high){
            int mid = (high+low)/2;
            if(check(arr,mid)<=k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        
        return ans;
    }
};