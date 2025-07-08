class Solution {
  public:
    int check(vector<int>&arr,int mid){
        int count =1, stHave = 0;
        
        for(int i=0;i<arr.size();i++){
            if(stHave + arr[i] <= mid){
                stHave+=arr[i];
            }else{
                count++;
                stHave = arr[i];
            }
        }
        return count;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int mx = arr[0];
        int sum =0;
        
        if(arr.size()<k) return -1;
        
        for(int a: arr){
            mx = max(mx,a);
            sum+=a;
        }
        
        int low = mx , high = sum,ans =-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(check(arr,mid) <= k){
                // ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};