class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;  // Store indices or values

        // Loop twice to simulate circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;

            while (!st.empty() && st.top() <= arr[index]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    res[index] = st.top();
                }
            }

            st.push(arr[index]);
        }

        return res;
    }
};
