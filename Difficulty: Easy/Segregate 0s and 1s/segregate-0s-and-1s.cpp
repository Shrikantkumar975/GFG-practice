class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int low = 0;
        int high = arr.size()-1;
        
        while(low < high){
            if(arr[low]==1){
                swap(arr[low],arr[high]);
                high--;
            }else low++;
        }
    }
};