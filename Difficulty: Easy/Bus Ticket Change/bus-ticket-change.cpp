class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        vector<int> v(3,0);
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==5) v[0]++;
            else if(arr[i]==10 && v[0]>0){
                v[1]++;
                v[0]--;
            }else if(arr[i]==20 && ((v[1]>0 && v[0]>0) || (v[0]>2))){
                v[2]++;
                if(v[1]>0){
                    v[1]--;
                    v[0]--;
                }else{
                    v[0]-=3;
                }
            }else{
                return false;
            }
        }
        
        return true;
    }
};