class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        // sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int i=0;
        int j=n-1;
        
        int k=0;
        
        while(k<=j){
            if(arr[k]==0){
                swap(arr[i++],arr[k]);
                k++;
            }else if(arr[k]==2){
                swap(arr[j--],arr[k]);
            }else{
                k++;
            }
        }
        
    }
};