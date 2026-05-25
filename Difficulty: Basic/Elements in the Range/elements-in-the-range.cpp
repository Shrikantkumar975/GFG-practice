class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int maxi = *max_element(arr.begin(),arr.end());
        
        vector<int> v(maxi+1,0);
        for(int &a: arr){
            v[a]++;
        }
        
        for(int i=start;i<=end;i++){
            if(!v[i]) return false;
        }
        
        return true;
    }
};
