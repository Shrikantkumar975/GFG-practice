class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_set<int> s;
        
        for(int a: arr){
            s.insert(a);
        }
        
        vector<int> v;
        for(int i=low;i<=high;i++){
            if(s.find(i)==s.end()){
                v.push_back(i);
            }
        }
        
        return v;
    }
};