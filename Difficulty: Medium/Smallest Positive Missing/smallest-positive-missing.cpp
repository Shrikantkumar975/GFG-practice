
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int i=0;
        while(i<arr.size()){
            if(arr[i]>0 && arr[i]<arr.size() && arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }else i++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i+1) return i+1;
        }
        
        return arr.size()+1;
    }
};