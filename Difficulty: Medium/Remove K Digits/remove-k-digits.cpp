class Solution {
  public:
    string removeKdig(string &s, int k) {
        stack<char> st;

        // Step 1–4: process digits
        for(char c : s) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Step 5: remove remaining digits from end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Step 6: build result from stack
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Step 7: remove leading zeros
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        // Step 8: handle empty
        return ans.empty() ? "0" : ans;
    }
};