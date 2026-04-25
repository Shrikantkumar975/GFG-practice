class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;

        for (int x : arr) {
            bool alive = true;

            while (!st.empty() && (st.back() * x < 0)) {
                int top = st.back();

                if (abs(top) > abs(x)) {
                    // top survives
                    alive = false;
                    break;
                }
                else if (abs(top) < abs(x)) {
                    // remove top, continue checking
                    st.pop_back();
                }
                else {
                    // equal → both removed
                    st.pop_back();
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push_back(x);
            }
        }

        return st;
    }
};