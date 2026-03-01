class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // int j=arr.size()-1;
        
        int i=0;
        
        for(int j=0;j<arr.size();j++){
            if(arr[j]!=0){
                arr[i]=arr[j];
                i++;
            }
        }
        
        while(i<arr.size()){
            arr[i]=0;
            i++;
        }
    }
};