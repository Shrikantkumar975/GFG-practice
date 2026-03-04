class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int> mpp;
        set<char> st;
        int maxi = -1;
        
        int i=0;
        int j=0;
        
        while(j<s.size()){
            mpp[s[j]]++;
            st.insert(s[j]);
            
            if(st.size()==k){
                maxi = max(maxi,j-i+1);
                j++;
            }else if(st.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)
                    st.erase(s[i]);
                i++;
                mpp[s[j]]--;
            }else{
                j++;
            }
        }
        return maxi;
    }
};