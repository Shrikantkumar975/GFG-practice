class Solution {
  public:
  stack<int> res;
    void rever(stack<int> &st){
        if(st.empty()) return;
        
        res.push(st.top());
        st.pop();
        
        rever(st);
    }
  
    void reverseStack(stack<int> &st) {
        // code here
        rever(st);
        
        st=res;
    }
};