class Solution {
public:
    vector<string> graycode(int n) {
        vector<string> ans;
        
        ans.push_back("0");
        if(n == 1) return {"0", "1"};
        
        ans = {"0", "1"};
        
        for(int i = 2; i <= n; i++){
            int size = ans.size();
            
            // reflect
            for(int j = size - 1; j >= 0; j--){
                ans.push_back(ans[j]);
            }
            
            // add prefix
            for(int j = 0; j < size; j++){
                ans[j] = "0" + ans[j];
            }
            
            for(int j = size; j < 2*size; j++){
                ans[j] = "1" + ans[j];
            }
        }
        
        return ans;
    }
};