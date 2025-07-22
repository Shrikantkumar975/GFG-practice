class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        map<int,int> m;
        
        for(int i=0;i<a.size();i++){
            m[a[i]]++;
        }
        
        for(int i=0;i<b.size();i++){
            if(m[b[i]]==0) return false;
            m[b[i]]--;
        }
        
        return true;
    }
};