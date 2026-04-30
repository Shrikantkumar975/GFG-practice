class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n=arr.size();
        // code here
        for(int i=0;i<arr.size();i++){
            if(2*i+1<n && arr[2*i+1]>arr[i]) return false;
            
            if(2*i+2<n && arr[2*i+2]>arr[i]) return false;
        }
        
        return true;
    }
};
