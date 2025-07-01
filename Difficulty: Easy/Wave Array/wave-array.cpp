class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        int i=0,j=1;
        
        while(i<arr.size()-1 && j<arr.size()){
            swap(arr[i],arr[j]);
            i+=2;
            j+=2;
        }
        
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        
    }
};