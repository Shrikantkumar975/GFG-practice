class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        
        int j=0;
        vector<vector<int>> res;
        res.push_back(arr[0]);
        
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<=res[j][1]) res[j][1]= max(res[j][1],arr[i][1]);
            else{
                res.push_back(arr[i]);
                j++;
            }
        }
        
        return res;
    }
};