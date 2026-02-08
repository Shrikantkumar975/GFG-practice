class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low<high){
            int mid = (high+low)/2;
            
            if(nums[mid]>nums[high]){
                low = mid+1;
                continue;
            }
            
            if(nums[mid]<nums[mid+1]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return high;
    }
};
