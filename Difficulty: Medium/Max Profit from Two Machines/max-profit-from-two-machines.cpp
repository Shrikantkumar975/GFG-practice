class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        
        vector<pair<int,int>> vec;

        for(int i = 0; i < a.size(); i++) {
            vec.push_back({abs(a[i] - b[i]), i});
        }

        sort(vec.begin(), vec.end(), greater<pair<int,int>>());

        int ans = 0;

        for(auto &[diff, i] : vec) {

            // Prefer A
            if(a[i] >= b[i]) {

                if(x > 0) {
                    ans += a[i];
                    x--;
                }
                else {
                    ans += b[i];
                    y--;
                }

            }
            // Prefer B
            else {

                if(y > 0) {
                    ans += b[i];
                    y--;
                }
                else {
                    ans += a[i];
                    x--;
                }
            }
        }

        return ans;
    }
};