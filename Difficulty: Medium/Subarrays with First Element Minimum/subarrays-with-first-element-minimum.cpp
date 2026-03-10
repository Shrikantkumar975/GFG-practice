class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        stack<int>st;
        int ans = 0;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int ind = st.top();
                st.pop();
                ans += i - ind;
            }
            st.push(i);
        }
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            ans+= n-ind;
        }
        return ans;
    }
};