class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        for(int i=0;i<arr.size()-1;i++){
            int max = i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]<arr[max]) max = j;
            }
            swap(arr[i],arr[max]);
        }
    }
};