class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(arr.begin(), arr.end());
        vector<int> ans;

        for(auto &q : queries) {
            int a = q[0], b = q[1];
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            ans.push_back(right - left);
        }

        return ans;
    }
};
