
class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {

        int n = arr.size();

        map<int, pair<int,int>> mp;

        vector<int> ans = {-1, -1, -1, -1};

        for(int a = 0; a < n; a++) {
            for(int b = a + 1; b < n; b++) {

                int sum = arr[a] + arr[b];

                if(mp.find(sum) != mp.end()) {

                    auto [c, d] = mp[sum];

                    if(a != c && a != d &&
                       b != c && b != d) {

                        vector<int> curr = {c, d, a, b};

                        if(ans[0] == -1 || curr < ans) {
                            ans = curr;
                        }
                    }
                }
                else {
                    mp[sum] = {a, b};
                }
            }
        }

        return ans;
    }
};
