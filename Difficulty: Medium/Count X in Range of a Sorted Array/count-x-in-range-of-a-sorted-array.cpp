class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
       unordered_map<int, vector<int>> pos;

        for(int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }

        vector<int> ans;
        for(auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            if(pos.find(x) == pos.end()) {
                ans.push_back(0);
                continue;
            }

            auto &v = pos[x];
            int left = lower_bound(v.begin(), v.end(), l) - v.begin();
            int right = upper_bound(v.begin(), v.end(), r) - v.begin();
            ans.push_back(right - left);
        }

        return ans;
    }
};
