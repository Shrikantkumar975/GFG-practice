class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int> st;
        st.push(arr[0]);
        arr[0]=-1;
        
        for(int i=1;i<arr.size();i++){
            
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                st.push(arr[i]);
                arr[i] = -1;
            }else{
                int a = st.top();
                st.push(arr[i]);
                arr[i] = a;
            }
            
        }
        
        return arr;
    }
};