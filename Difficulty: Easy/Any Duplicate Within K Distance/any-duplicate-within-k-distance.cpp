
class Solution {
public:
    bool checkWithinK(vector<int>& arr, int k) {
        unordered_set<int> st;

        for (int i = 0; i < arr.size(); i++) {

            // Duplicate found within distance k
            if (st.find(arr[i]) != st.end()) {
                return true;
            }

            st.insert(arr[i]);

            // Maintain only the last k elements
            if (i >= k) {
                st.erase(arr[i - k]);
            }
        }

        return false;
    }
};
