class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for (char ch : s) {
            // When we encounter a closing bracket
            if (ch == ')') {
                char top = st.top();
                st.pop();
                
                // Assume redundancy until we find an operator
                bool isRedundant = true;

                while (top != '(') {
                    // If any operator is found, the bracket is necessary
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    top = st.top();
                    st.pop();
                }

                // If no operator was found inside the brackets, return true
                if (isRedundant) return true;
            } 
            else {
                // Push opening brackets, operators, and operands onto stack
                st.push(ch);
            }
        }
        return false;
    }
};