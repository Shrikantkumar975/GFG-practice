class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int> summ(arr.size());
        int sum = 0;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            summ[i]=sum;
        }
        
        vector<int> ans;
        
        for(auto a: queries){
            int l = a[0];
            int r = a[1];
            
            if(l==0) ans.push_back(summ[r]/(r-l+1));
            else{
                ans.push_back((summ[r]-summ[l-1])/(r-l+1));
            }
        }
        
        return ans;
    }
};