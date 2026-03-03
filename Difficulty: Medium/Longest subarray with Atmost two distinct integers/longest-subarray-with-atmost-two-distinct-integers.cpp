class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int i=0;
        int j=0;
        unordered_set<int> st;
        unordered_map<int,int> mpp;
        int maxi=0;
        
        while(j<arr.size()){
            mpp[arr[j]]++;
            st.insert(arr[j]);
            if(st.size()<=2){
                maxi = max(maxi,j-i+1);
            }else if(st.size()>2){
                mpp[arr[i]]--;
                if(mpp[arr[i]]==0) st.erase(arr[i]);
                i++;
            }
            j++;
        }
        
        return maxi;
    }
};