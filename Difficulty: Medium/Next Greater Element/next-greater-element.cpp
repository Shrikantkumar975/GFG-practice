class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        st.push(arr[n-1]);
        arr[n-1]= -1;
        
        for(int i=arr.size()-2;i>=0;i--){
            
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                st.push(arr[i]);
                arr[i] = -1;
            }else{
                int now = st.top();
                st.push(arr[i]);
                arr[i] = now;
            }
        }
        
        return arr;
    }
};