class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        
        vector<int> ans;
        
        int i=0;
        int j=0;
        
        while(i<a.size() && j<b.size()){
            if(a[i]>b[j]){
                j++;
            }
            else if(b[j]> a[i]){
                i++;
            }else{
                if(ans.size()==0 || ans.back()!= a[i]){
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};