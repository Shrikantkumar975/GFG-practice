class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    // Traverse the array from right to left
    for (int i = 2 * n - 1; i >= 0; i--) {

        // Pop elements from the stack that are less
        // than or equal to the current element
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }

        // If the stack is not empty, the top element
        // is the next greater element
        if (i < n && !st.empty()) {
            res[i] = st.top();
        }

        st.push(arr[i % n]);
    }

    return res;
}

};