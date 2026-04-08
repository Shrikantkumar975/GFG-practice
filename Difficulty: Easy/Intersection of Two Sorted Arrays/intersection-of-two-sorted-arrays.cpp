class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st;
        
        for(int i: a){
            st.insert(i);
        }
        
        vector<int> ans;
        
        for(int i: b){
            if(st.find(i) != st.end()){
                if(ans.size()==0 || ans.back()!=i) ans.push_back(i);
            }
        }
        
        return ans;
    }
};