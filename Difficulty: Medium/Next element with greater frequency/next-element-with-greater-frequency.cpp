class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> freq;
        stack<int> st;

        // Count frequency of each element
        for (int x : arr) {
            freq[x]++;
        }

        // Traverse array
        for (int i = 0; i < n; i++) {
            // If current element has higher frequency
            while (!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
