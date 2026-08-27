class Solution {
  public:
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int res=0;
    
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int currPop = st.top();
                st.pop();
    
                int pse = st.empty()?-1:st.top();
    
                res = max(res,heights[currPop]*(i-pse-1));
            }
            st.push(i);
        }
    
        while(!st.empty()){
            int currPop = st.top();
            st.pop();
    
            int pse = st.empty()?-1:st.top();
    
            res = max(res,heights[currPop]*(n-pse-1));
        }
    
        return res;
    }
    
    int maxArea(vector<vector<int>>& mat) {
       vector<int> m(mat[0].size(),0);
       int maxi=0;
       
       for(int i=0;i<mat.size();i++){
           
           for(int j=0;j<mat[0].size();j++){
               if(mat[i][j]==0)
                    m[j]=0;
                else{
                    m[j]++;
                }
           }
            
            vector<int> temp = m;
            
            sort(temp.begin(),temp.end());
            
            maxi= max(maxi,largestRectangleArea(temp));
       }
       return maxi;
    }
};