class Solution {
  public:
  
    int check(vector<int> &arr,int mid){
        int count =0;
        
        for(int &a: arr){
            count+=ceil(a*1.0/mid);
        }
        
        return count;
    }
    
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = 1e6;
        int ans=0;
        
        while(low<=high){
            int mid =  low + (high - low )/2;
            
            if(check(arr,mid) <= k){
                ans = mid;
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        
        return ans;
    }
};